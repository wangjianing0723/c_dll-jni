#include "com_hebca_jni_jniInterface.h"
#include "jni.h"
#include "jni_md.h"
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "hebca_com_c_dll.h"


jstring charTojstring(JNIEnv* env, const char* str);
char* jstringToChar(JNIEnv *env, jstring jstr);
jstring charTojstring(JNIEnv* env, const char* str)
{
	jstring rtn = 0;
	int slen = strlen(str);
	unsigned short * buffer = 0;
	if (slen == 0)
		rtn = (env)->NewStringUTF(str);
	else {
		int length = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str, slen, NULL, 0);
		buffer = (unsigned short *)malloc(length * 2 + 1);
		if (MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str, slen, (LPWSTR)buffer, length) > 0)
			rtn = (env)->NewString((jchar*)buffer, length);
		// ÊÍ·ÅÄÚ´æ
		free(buffer);

	}
	return rtn;
}
char* jstringToChar(JNIEnv *env, jstring jstr)
{
	int length = (env)->GetStringLength(jstr);
	const jchar* jcstr = (env)->GetStringChars(jstr, 0);
	char* rtn = (char*)malloc(length * 2 + 1);
	int size = 0;
	size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)jcstr, length, rtn,
		(length * 2 + 1), NULL, NULL);
	if (size <= 0)
		return NULL;
	(env)->ReleaseStringChars(jstr, jcstr);
	rtn[size] = 0;
	return rtn;
	//char* rtn = NULL;
	//jclass clsstring = env->FindClass("java/lang/String");
	//jstring strencode = env->NewStringUTF("GB2312");
	//jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	//jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	//jsize alen = env->GetArrayLength(barr);
	//jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	//if (alen > 0) {
	//	rtn = (char*)malloc(alen + 1);
	//	memcpy(rtn, ba, alen);
	//	rtn[alen] = 0;
	//}
	//env->ReleaseByteArrayElements(barr, ba, 0);
	//return rtn;
}
JNIEXPORT jint JNICALL Java_com_hebca_jni_jniInterface_InitKey
(JNIEnv *, jobject)
{
	int rv = -214747;
	rv = InitKey();
	return rv;
}
JNIEXPORT jint JNICALL Java_com_hebca_jni_jniInterface_SelectCert
(JNIEnv *, jobject)
{
	int rv = -214747;
	rv = SelectCert();
	return rv;
}
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_GetSignCert
(JNIEnv * sd, jobject)
{
	int rv = -2147;
	unsigned char *signcert;
	char cert[3072] = "";
	signcert = GetSignCert();
	rv = strlen((const char*)signcert);
	memcpy(cert, signcert, rv);
	return charTojstring(sd,cert);
}
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_Sm3Hash
(JNIEnv * sd, jobject, jstring a)
{
	int rv = -2147;
	unsigned char *ha;
	char hash[128] = "";
	char* ora = jstringToChar(sd,a);
	ha = Sm3Hash((unsigned char*)ora);
	rv = strlen((const char*)ha);
	memcpy(hash, ha, rv);
	return charTojstring(sd, hash);
}

JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_GetSubject
(JNIEnv * sd, jobject)
{
	int rv = -2147;
	unsigned char *sub;
	char subject[300] = "";
	sub = GetSubject();
	rv = strlen((const char*)sub);
	memcpy(subject, sub, rv);
	return charTojstring(sd, subject);
}

JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_Sign
(JNIEnv *sd, jobject, jstring a)
{
	int rv = -2147;
	unsigned char *si;
	char sign[128] = "";
	char* ora = jstringToChar(sd, a);
	si = Sign((unsigned char*)ora);
	rv = strlen((const char*)si);
	memcpy(sign, si, rv);
	return charTojstring(sd, sign);
}
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_Pic
(JNIEnv * sd, jobject)
{
	int rv = -2147;
	unsigned char *pi;
	char pic[10240] = "";
	pi = GetPic();
	rv = strlen((const char*)pi);
	memcpy(pic, pi, rv);
	return charTojstring(sd, pic);
}
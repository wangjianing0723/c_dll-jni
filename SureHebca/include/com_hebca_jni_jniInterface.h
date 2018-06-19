/* DO NOT EDIT THIS FILE - it is machine generated */
#include "jni.h"
/* Header for class com_hebca_jni_jniInterface */

#ifndef _Included_com_hebca_jni_jniInterface
#define _Included_com_hebca_jni_jniInterface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    InitKey
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_hebca_jni_jniInterface_InitKey
  (JNIEnv *, jobject);

/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    SelectCert
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_hebca_jni_jniInterface_SelectCert
  (JNIEnv *, jobject);

/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    GetSignCert
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_GetSignCert
  (JNIEnv *, jobject);

/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    GetSubject
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_GetSubject
  (JNIEnv *, jobject);

/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    Sign
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_Sign
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    Sm3Hash
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_Sm3Hash
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_hebca_jni_jniInterface
 * Method:    Pic
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hebca_jni_jniInterface_Pic
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
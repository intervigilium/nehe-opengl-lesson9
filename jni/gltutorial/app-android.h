#ifndef APP_ANDROID_H_INCLUDED
#define APP_ANDROID_H_INCLUDED

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_intervigil_gltest_TutorialRenderer
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_intervigil_gltest_TutorialRenderer_nativeInit
  (JNIEnv *, jclass);

/*
 * Class:     com_intervigil_gltest_TutorialRenderer
 * Method:    nativeResize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_intervigil_gltest_TutorialRenderer_nativeResize
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_intervigil_gltest_TutorialRenderer
 * Method:    nativeRender
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_intervigil_gltest_TutorialRenderer_nativeRender
  (JNIEnv *, jclass);

/*
 * Class:     com_intervigil_gltest_TutorialView
 * Method:    nativePause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_intervigil_gltest_TutorialView_nativePause
  (JNIEnv *, jclass);

/*
 * Class:     com_intervigil_gltest_TutorialView
 * Method:    nativeResume
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_intervigil_gltest_TutorialView_nativeResume
  (JNIEnv *, jclass);

/*
 * Class:     com_intervigil_gltest_TutorialView
 * Method:    nativeHandleKeyEvent
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_intervigil_gltest_TutorialView_nativeHandleKeyEvent
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif

#endif // !APP_ANDROID_H_INCLUDED



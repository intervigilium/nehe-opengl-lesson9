
#include <GLES/gl.h>
#include <android/log.h>
#include "app-android.h"
#include "stars.h"

/* Call to initialize the graphics state */
void
Java_com_intervigil_gltest_TutorialRenderer_nativeInit( JNIEnv* env, jclass clazz )
{
	initGL();
}

void
Java_com_intervigil_gltest_TutorialRenderer_nativeResize( JNIEnv* env, jclass clazz, jint w, jint h )
{
    __android_log_print(ANDROID_LOG_INFO, "GLTutorial", "resize w=%d h=%d", w, h);
}

void
Java_com_intervigil_gltest_TutorialView_nativePause( JNIEnv* env, jclass clazz )
{

}

void
Java_com_intervigil_gltest_TutorialView_nativeResume( JNIEnv* env, jclass clazz )
{

}

/* Call to render the next GL frame */
void
Java_com_intervigil_gltest_TutorialRenderer_nativeRender( JNIEnv* env, jclass clazz )
{
	drawGLScene();
}

/* Handles key events in native code */
void
Java_com_intervigil_gltest_TutorialView_nativeHandleKeyEvent( JNIEnv* env, jclass clazz )
{

}

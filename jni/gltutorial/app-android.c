
#include <GLES/gl.h>
#include <android/log.h>
#include <zip.h>
#include "app-android.h"
#include "def.h"
#include "stars.h"

struct zip* APKArchive;

static void loadAPK (const char* apkPath) {
	LOGI("Loading APK %s", apkPath);
	APKArchive = zip_open(apkPath, 0, NULL);
	if (APKArchive == NULL) {
		LOGE("Error loading APK");
		return;
	}
}


/* Call to initialize the graphics state */
void
Java_com_intervigil_gltest_TutorialRenderer_nativeInit( JNIEnv* env, jclass clazz, jstring apkPath )
{
	jboolean isCopy;
	const char* str = (*env)->GetStringUTFChars(env, apkPath, &isCopy);
	loadAPK(str);
	initGL();
}

void
Java_com_intervigil_gltest_TutorialRenderer_nativeResize( JNIEnv* env, jclass clazz, jint w, jint h )
{
	LOGI("nativeResize (%i,%i)", w, h);

	if(h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	const float ratio = w/(float)h;
	glLoadIdentity();
	glOrthof(0, 15, 15/ratio, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
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

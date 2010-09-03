#include <stdlib.h>
#include <math.h>
#include <GLES/gl.h>
#include <android/log.h>
#include <zip.h>
#include "app-android.h"
#include "def.h"
#include "stars.h"

struct zip* APKArchive;
GLuint* texturePtr;

#undef PI
#define PI 3.1415926535897932f

static void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar) {
    GLfloat xmin, xmax, ymin, ymax;

    ymax = zNear * (GLfloat)tan(fovy * PI / 360);
    ymin = -ymax;
    xmin = ymin * aspect;
    xmax = ymax * aspect;

    glFrustumx((GLfixed)(xmin * 65536), (GLfixed)(xmax * 65536),
               (GLfixed)(ymin * 65536), (GLfixed)(ymax * 65536),
               (GLfixed)(zNear * 65536), (GLfixed)(zFar * 65536));
}

/* Call to initialize the graphics state */
void
Java_com_intervigil_gltest_TutorialRenderer_nativeInit( JNIEnv* env, jclass clazz, jintArray textures )
{
	int size = (*env)->GetArrayLength(env, textures);
	texturePtr = (GLuint*) malloc(sizeof(GLuint) * size);
	(*env)->GetIntArrayRegion(env, textures, 0, size, texturePtr);
	initGL(texturePtr);
}

void
Java_com_intervigil_gltest_TutorialRenderer_nativeResize( JNIEnv* env, jclass clazz, jint w, jint h )
{
	LOGI("nativeResize (%i,%i)", w, h);
	if (h == 0) {                                    	// Prevent A Divide By Zero By
		h = 1;                                       	// Making Height Equal One
	}

	glViewport(0, 0, w, h);                       		// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
	glLoadIdentity();                                   // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, ((GLfloat) w)/h, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);                         // Select The Modelview Matrix
	glLoadIdentity();
}

void
Java_com_intervigil_gltest_TutorialView_nativePause( JNIEnv* env, jclass clazz )
{

}

void
Java_com_intervigil_gltest_TutorialView_nativeResume( JNIEnv* env, jclass clazz )
{

}

void
Java_com_intervigil_gltest_TutorialView_nativeCleanup( JNIEnv* env, jclass clazz )
{
	if (texturePtr) {
		free(texturePtr);
	}
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

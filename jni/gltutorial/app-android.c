/* 	app-android.c
 *
 *	Copyright (c) 2010 Ethan Chen
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *	THE SOFTWARE.
 */

#include <stdlib.h>
#include <GLES/gl.h>
#include <android/log.h>
#include "app-android.h"
#include "def.h"
#include "stars.h"
#include "gl-extras.h"

/* Handle to our textures, loaded by the Android system */
GLuint* texturePtr;

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

void
Java_com_intervigil_gltest_TutorialRenderer_nativeRender( JNIEnv* env, jclass clazz )
{
	drawGLScene();
}

void
Java_com_intervigil_gltest_TutorialView_nativeHandleKeyEvent( JNIEnv* env, jclass clazz )
{

}

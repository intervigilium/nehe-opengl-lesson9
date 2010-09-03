/* 	stars.c
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
#include <GLES/glext.h>
#include "def.h"
#include "stars.h"


static star stars[NUM_STARS];

static GLfloat zoom = -15.0f;
static GLfloat tilt = 90.0f;
static GLfloat spin;
static GLuint* textures;

GLfloat vertices[12] = {
	-1.0f, -1.0f, 0.0f, 	//Bottom Left
	1.0f, -1.0f, 0.0f, 		//Bottom Right
	-1.0f, 1.0f, 0.0f,	 	//Top Left
	1.0f, 1.0f, 0.0f 		//Top Right
};

GLfloat texCoords[8] = {
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
};

int initGL(GLuint* texturePtr) {
	if (texturePtr) {
		textures = texturePtr;
		// do the GL initialization stuff
		glEnable(GL_TEXTURE_2D); 							// Enable Texture Mapping
		glShadeModel(GL_SMOOTH); 							// Enable Smooth Shading
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f); 				// Black Background
		glClearDepthf(1.0f); 								// Depth Buffer Setup
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 	// Really Nice Perspective Calculations
		glBlendFunc(GL_SRC_ALPHA,GL_ONE); 					// Set The Blending Function For Translucency
		glEnable(GL_BLEND); 								// Enable Blending

		for (int i = 0; i < NUM_STARS; i++) {
			stars[i].angle = 0.0f;
			stars[i].dist = ((float) i)/NUM_STARS * 5.0f;
			stars[i].r = rand() % 256;
			stars[i].g = rand() % 256;
			stars[i].b = rand() % 256;
		}
		LOGI("GL initialized");
		return 1;
	} else {
		LOGE("Unable to load textures");
		return 0;
	}
}

int drawGLScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, textures[0]);

	for (int i = 0; i < NUM_STARS; i++) {
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, zoom);
		glRotatef(tilt, 1.0f, 0.0f, 0.0f);
		// center axis on current star
		glRotatef(stars[i].angle, 0.0f, 1.0f, 0.0f);
		glTranslatef(stars[i].dist, 0.0f, 0.0f);
		// cancel current star's angle & screen tilt
		glRotatef(-stars[i].angle, 0.0f, 1.0f, 0.0f);
		glRotatef(-tilt, 1.0f, 0.0f, 0.0f);

		if (TWINKLE_ON) {
			glColor4ub(stars[NUM_STARS - i].r, stars[NUM_STARS - i].g, stars[NUM_STARS - i].b, 255);
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, vertices);
			glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		// rotate the uncolored star here
		glRotatef(spin, 0.0f, 0.0f, 1.0f);
		glColor4ub(stars[i].r, stars[i].g, stars[i].b, 255);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);


		spin += 0.01f;
		stars[i].angle += ((float) i)/NUM_STARS;
		stars[i].dist -= 0.01f;

		// move stars that hit the center back out
		if (stars[i].dist < 0.0f) {
			stars[i].dist += 5.0f;
			stars[i].r = rand() % 256;
			stars[i].g = rand() % 256;
			stars[i].b = rand() % 256;
		}
	}
	return 1;
}



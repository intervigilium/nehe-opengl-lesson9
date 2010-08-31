
#include <stdlib.h>
#include <GLES/gl.h>
#include <android/log.h>
#include "stars.h"
#include "utils.h"
#include "def.h"

int twinkle;
star stars[NUM_STARS];

GLfloat zoom = -15.0f;
GLfloat tilt = 90.0f;
GLfloat spin;
GLuint textures[1];

int loadGLTextures() {
	int width = 0;
	int height = 0;
	textures[0] = loadTextureFromPNG("star.png", &width, &height);

	return textures[0];
}

int initGL() {
	if (loadGLTextures()) {
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

		return 1;
	} else {
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

		if (twinkle) {
			glColor4ub(stars[NUM_STARS - i].r, stars[NUM_STARS - i].g, stars[NUM_STARS - i].b, 255);
			// draw twinkle here
		}
		// rotate the uncolored star here
		glRotatef(spin, 0.0f, 0.0f, 1.0f);
		glColor4ub(stars[i].r, stars[i].g, stars[i].b, 255);
		// draw star here

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



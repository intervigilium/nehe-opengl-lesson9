#ifndef STARS_H_
#define STARS_H_

#define NUM_STARS 50
#define TWINKLE_ON 0

typedef struct {
	int r;
	int g;
	int b;
	GLfloat dist;
	GLfloat angle;
} star;

int initGL();

int drawGLScene();

#endif /* STARS_H_ */

#ifndef DRAW_FUNCTIONS_HPP
#define DRAW_FUNCTIONS_HPP

#include <glut.h>

extern unsigned int texture;
extern GLfloat cameraAngle;

void drawCone(GLdouble radius, GLdouble height, GLint slices, GLint stacks);
void drawTorus(GLfloat innerRadius, GLfloat outerRadius, GLint slices, GLint stacks);
void drawCube(GLfloat size);

#endif

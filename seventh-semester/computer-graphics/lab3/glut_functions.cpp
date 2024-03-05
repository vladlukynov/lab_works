#include <iostream>
#include <glut.h>

#include "include/glut_functions.hpp"
#include "include/platform.hpp"
#include "include/octahedron.hpp"

GLdouble cubeSize = 10.0;
GLdouble octahedronSize = 0.5;
GLdouble octahedronStartPos[] = {0.0, -0.5, -5.0};
GLdouble deltaYCameraPos = 0.0;

Octahedron octahedron(octahedronSize, octahedronStartPos);
Platform platform(cubeSize, octahedronSize, octahedronStartPos);

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
        glTranslated(0.0, -deltaYCameraPos, 0.0);
        
        octahedron.draw();
        platform.draw();
    }
    glPopMatrix();

    glFlush();
}

void handleSpecialKeys(int key, int, int) {
    switch (key) {
    case GLUT_KEY_UP:
        deltaYCameraPos += 0.1;
        display();
        break;

    case GLUT_KEY_DOWN:
        deltaYCameraPos -= 0.1;
        display();
        break;

    case GLUT_KEY_F1:
        octahedron.startSquareSideAnimation();
        break;

    case GLUT_KEY_F2:
        octahedron.startTriangleSideAnimation();
        break;
    
    case GLUT_KEY_F3:
        octahedron.reverseRotateDirection();
        break;

    default:
        break;
    }
}

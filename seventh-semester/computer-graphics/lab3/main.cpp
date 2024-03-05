#include <glut.h>

#include "include/glut_functions.hpp"

const int WIDTH = 640;
const int HEIGHT = 640;
const char TITLE[] = "LAB 3";

void initLightning();
void initPerspective();

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow(TITLE);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initPerspective();
    initLightning();

    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeys);
    glutMainLoop();

    return 0;
}

void initPerspective() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble) HEIGHT / (GLdouble) WIDTH, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initLightning() {
    GLfloat colorLightning[] = {1.0, 1.0, 1.0};
    GLfloat position[] = {0.0, 3.0, 0.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, colorLightning);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, colorLightning);
    glLightfv(GL_LIGHT0, GL_SPECULAR, colorLightning);
}

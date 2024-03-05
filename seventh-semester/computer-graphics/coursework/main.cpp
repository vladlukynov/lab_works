#include "include/glut_functions.hpp"

#include <glut.h>

const int WIDTH = 640;
const int HEIGHT = 640;
const char TITLE[] = "Coursework";

void init();

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow(TITLE);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeys);
    glutMainLoop();

    return 0;
}

void init() {
    initGlutFunctions(100);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble) HEIGHT / (GLdouble) WIDTH, 1.0, 6.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

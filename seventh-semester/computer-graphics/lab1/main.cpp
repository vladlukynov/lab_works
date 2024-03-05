#include <glut.h>

#include "include/functions.hpp"

const int WIDTH = 640;
const int HEIGHT = 640;
const char TITLE[] = "LAB 1";

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow(TITLE);

    glEnable(GL_DEPTH_TEST);
    gluPerspective(45.0, (GLdouble) HEIGHT / (GLdouble) WIDTH, 1.0, 6.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutSpecialFunc(handleSpecialKeys);
    glutMainLoop();

    return 0;
}

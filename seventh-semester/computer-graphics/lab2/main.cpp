#include <iostream>
#include <stdexcept>
#include <glut.h>

#include "include/functions.hpp"

const int WIDTH = 640;
const int HEIGHT = 640;
const char TITLE[] = "LAB 2";

void init();

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow(TITLE);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(specialKeyHandle);

    try {
        init();
    } catch (std::runtime_error &error) {
        std::cerr << error.what() << "\n";
        return 1;
    }

    glutMainLoop();

    return 0;
}

void init() {
    std::cout << "Light changing mode selected by default\n";
    initTexture();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble) HEIGHT / (GLdouble) WIDTH, 1.0, 6.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

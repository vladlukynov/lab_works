#include "include/functions.hpp"

#include <glut.h>

#include "include/draw_functions.hpp"

const int ENTER_KEY_CODE = 13;
const int RIGHT_KEY_CODE = 102;
const int LEFT_KEY_CODE = 100;
window_state_t WINDOW_STATE = PAGE_1;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
        glTranslatef(0.0, 0.0, -4.0);

        glColor3f(1.0, 0.0, 0.0);
        drawCube();

        glColor3f(0.0, 1.0, 0.0);
        drawTorus();

        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(4.0, 0.0, 0.0);
        drawComposition();
    }
    glPopMatrix();

    glFlush();
}

void handleKeyboard(unsigned char key, int, int) {
    if (key == ENTER_KEY_CODE) {
        switch (WINDOW_STATE) {
            case PAGE_1:
                rotateTorus();
                break;
            case PAGE_2:
                movePrimitives();
                break;
        }
    }
}

void handleSpecialKeys(int key, int, int) {
    const GLfloat startPos = 0.0;
    const GLfloat endPos = 4.0;
    const GLfloat delta = 0.01;
    const int times = (int) ((endPos - startPos) / delta);

    if ((key == RIGHT_KEY_CODE) && WINDOW_STATE == PAGE_1) {
        for (int i = 0; i < times; i++) {
            glTranslatef(-delta, 0.0, 0.0);
            display();
        }
        WINDOW_STATE = PAGE_2;
    } else if ((key == LEFT_KEY_CODE) && WINDOW_STATE == PAGE_2) {
        for (int i = 0; i < times; i++) {
            glTranslatef(delta, 0.0, 0.0);
            display();
        }
        WINDOW_STATE = PAGE_1;
    }
}

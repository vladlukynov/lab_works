#include "include/draw_functions.hpp"

#include <glut.h>

#include "include/functions.hpp"

const GLfloat xConeStartPosition = -1.0;
const GLfloat xConeEndPosition = 0.0;
const GLfloat yConeStartPosition = 0.0;
const GLfloat yConeEndPosition = -0.5;
const GLfloat xCylinderStartPosition = 1.0;
const GLfloat xCylinderEndPosition = 0.0;

GLfloat yTorusRotated = 0.0;
GLfloat xConePosition = xConeStartPosition;
GLfloat yConePosition = yConeStartPosition;
GLfloat xCylinderPosition = xCylinderStartPosition;

void drawCube() {
    glutWireCube(1);
}

void drawTorus() {
    GLdouble innerRadius = 0.1;
    GLdouble outerRadius = 0.4;
    GLint sides = 50;
    GLint rings = 50;

    glPushMatrix();
    {
        glRotatef(yTorusRotated, 0.0, 1.0, 0.0);
        glutWireTorus(innerRadius, outerRadius, sides, rings);
    }
    glPopMatrix();
}

void drawComposition() {
    // Create Sphere
    glutSolidSphere(0.5, 50, 50);

    // Create Cone
    glPushMatrix();
    {
        glTranslatef(xConePosition, yConePosition, 0.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, -0.5);
        glutSolidCone(0.3, 1.0, 50, 50);
    }
    glPopMatrix();

    // Create Cylinder
    glPushMatrix();
    {
        GLUquadric *quadric = gluNewQuadric();

        glTranslatef(xCylinderPosition, 0.0, 0.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, -0.5);
        gluCylinder(quadric, 0.3, 0.3, 1.0, 50, 50);
    }
    glPopMatrix();
}

void rotateTorus() {
    const GLfloat deltaY = 0.1;
    static bool isRotated = false;

    while ((!isRotated && (yTorusRotated < 45.0)) || (isRotated && (yTorusRotated > 0.0))) {
        yTorusRotated += !isRotated ? deltaY : -deltaY;
        display();
    }

    isRotated = !isRotated;
}

void movePrimitives() {
    static bool isMoved = false;
    const int times = 1000;
    const GLfloat xConePositionDelta = (xConeEndPosition - xConeStartPosition) / times;
    const GLfloat yConePositionDelta = (yConeEndPosition - yConeStartPosition) / times;
    const GLfloat xCylinderPositionDelta = (xCylinderEndPosition - xCylinderStartPosition) / times;

    for (int i = 0; i < times; i++) {
        xConePosition += !isMoved ? xConePositionDelta : -xConePositionDelta;
        yConePosition += !isMoved ? yConePositionDelta : -yConePositionDelta;
        xCylinderPosition += !isMoved ? xCylinderPositionDelta : -xCylinderPositionDelta;

        display();
    }
    isMoved = !isMoved;
}

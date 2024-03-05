#include <cmath>
#include <glut.h>

#include "include/platform.hpp"

Platform::Platform() {
    this->cubeSize = 1.0;
    this->octahedronSize = 1.0;
    this->octahedronPosition = new GLdouble[3] {0.0, 0.0, 0.0};
}

Platform::Platform(GLdouble cubeSize, GLdouble octahedronSize, GLdouble* octahedronPosition) {
    this->cubeSize = cubeSize;
    this->octahedronSize = octahedronSize;
    this->octahedronPosition = new GLdouble[3] {octahedronPosition[0], octahedronPosition[1], octahedronPosition[2]};
}

Platform::~Platform() {
    delete[] this->octahedronPosition;
}

void Platform::draw() {
    glPushMatrix();
    {
        GLdouble delta = 1.0 / std::sqrt(6.0) * this->octahedronSize;

        glTranslated(this->octahedronPosition[0],
                     this->octahedronPosition[1] - 0.5 * this->cubeSize - delta,
                     this->octahedronPosition[2]);
        glRotated(45.0, 0.0, 1.0, 0.0);
        glutSolidCube(this->cubeSize);
    }
    glPopMatrix();
}

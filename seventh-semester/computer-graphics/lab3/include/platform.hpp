#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <glut.h>

class Platform {
public:
    Platform();
    Platform(GLdouble cubeSize, GLdouble octahedronSize, GLdouble* octahedronPosition);
    ~Platform();

    void draw();
private:
    GLdouble cubeSize;
    GLdouble octahedronSize;
    GLdouble* octahedronPosition;
};

#endif

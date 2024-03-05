#ifndef OCTAHERDRON_HPP
#define OCTAHERDRON_HPP

#include <glut.h>

class Octahedron {
public:
    Octahedron();
    Octahedron(GLdouble size, GLdouble* position);
    ~Octahedron();

    void draw();
    void startSquareSideAnimation();
    void startTriangleSideAnimation();
    void reverseRotateDirection();
private:
    void drawFigure();
    void Octahedron::initTexture();

    GLdouble rotateAngle;
    GLdouble liftAngle;
    GLdouble size;
    GLdouble* position;
    bool rotateDirection;
    GLdouble squareSideAnimationAngle;
    GLdouble triangleAnimationAngle;
};

#endif

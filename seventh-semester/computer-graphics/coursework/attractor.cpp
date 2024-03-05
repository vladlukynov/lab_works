#include <cmath>

#include "include/attractor.hpp"

#include <glut.h>

const GLint slices = 50;
const GLint stacks = 50;
const GLint loops = 50;

Attractor::Attractor(vector_t position, float height, float radius, float attractionLength) {
    this->height = height;
    this->radius = radius;
    this->position = position;
    this->attractionLength = attractionLength;
}

void Attractor::draw() {
    drawCylinder();
}

vector_t Attractor::getPosition() {
    return this->position;
}

float Attractor::getRadius() {
    return this->radius;
}

bool Attractor::isAttracted(vector_t position) {
    float distance = std::sqrt(std::pow(this->position.x - position.x, 2.0) +
                               std::pow(this->position.y - position.y, 2.0) +
                               std::pow(this->position.z - position.z, 2.0));

    if ((position.y <= this->position.y + this->height / 2.0) &&
        (this->position.y - this->height / 2.0 <= position.y) &&
        (distance <= this->attractionLength + this->radius)) {
        return true;
    }

    return false;
}

void Attractor::drawCylinder() {
    GLUquadric *quadric = gluNewQuadric();

    glPushMatrix();
    {
        glTranslatef(this->position.x, this->position.y, this->position.z);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        
        glTranslatef(0.0, 0.0, -this->height / 2.0);
        gluCylinder(quadric, this->radius, this->radius, this->height, slices, stacks);

        glRotatef(180.0, 1.0, 0.0, 0.0);
        this->drawDisk();
        glRotatef(-180.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, this->height);
        this->drawDisk();
    }
    glPopMatrix();
}

void Attractor::drawDisk() {
    GLUquadric *quadric = gluNewQuadric();

    gluDisk(quadric, 0.0, this->radius, slices, loops);
}

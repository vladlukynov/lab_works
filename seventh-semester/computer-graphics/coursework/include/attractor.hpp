#ifndef ATTRACTOR_HPP
#define ATTRACTOR_HPP

#include "types.hpp"

class Attractor {
public:
    Attractor(vector_t position, float height, float radius, float attractionLength);
    void draw();
    vector_t getPosition();
    float getRadius();
    bool isAttracted(vector_t position);

private:
    void drawCylinder();
    void drawDisk();

    float radius;
    float height;
    vector_t position;
    float attractionLength;
};

#endif

#ifndef PARTICE_HPP
#define PARTICE_HPP

#include <deque>

#include "types.hpp"

class Particle {
public:
    Particle(vector_t accelerationVector, float lifecycle, float timestamp);
    void draw(vector_t position, float dtime);
    bool isLifecycleOut(float dtime);
    vector_t getPosition();
    void setAcceleration(vector_t acceleration);
    void setIsAttracted();

private:
    void drawTrace(vector_t position);
    void addCurrentPositionToTrace();

    vector_t acceleration;
    vector_t position;
    float lifecycle;
    float timestamp;
    bool isAttracted;
    std::deque<vector_t> trace;
};

#endif

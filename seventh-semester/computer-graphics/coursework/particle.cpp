#include "include/particle.hpp"
#include "include/constants.hpp"
#include "include/types.hpp"

#include <cmath>
#include <glut.h>

Particle::Particle(vector_t accelerationVector, float lifecycle, float timestamp) {
    this->acceleration = accelerationVector;
    this->position = {0.0, 0.0, 0.0};
    this->timestamp = timestamp;
    this->lifecycle = lifecycle;
    this->isAttracted = false;
}

void Particle::draw(vector_t position, float dtime) {
    vector_t speed; 
    if (!isAttracted) {
        speed = {this->acceleration.x * this->lifecycle - this->acceleration.x * (dtime - this->timestamp),
                 this->acceleration.y * this->lifecycle - this->acceleration.y * (dtime - this->timestamp),
                 this->acceleration.z * this->lifecycle - this->acceleration.z * (dtime - this->timestamp)};
    } else if (std::sqrt(std::pow(this->position.x - attractor.getPosition().x - 1.0, 2.0) +
                         std::pow(this->position.z - attractor.getPosition().z, 2.0)) <= attractor.getRadius()) {
        this->lifecycle = 0.0;
        speed = {0.0, 0.0, 0.0};
    } else {
        speed = {this->acceleration.x + this->acceleration.x * 2,
                 this->acceleration.y + this->acceleration.y * 2,
                 this->acceleration.z + this->acceleration.z * 2};
    }

    vector_t nextPosition = {this->position.x + speed.x,
                             this->position.y + speed.y,
                             this->position.z + speed.z};

    this->addCurrentPositionToTrace();
    this->position = nextPosition;

    glPushMatrix();
    {
        glTranslatef(nextPosition.x + position.x, nextPosition.y + position.y, nextPosition.z + position.z);
        glutSolidSphere(0.01, 50, 50);
    }
    glPopMatrix();

    this->drawTrace(position);
}

void Particle::drawTrace(vector_t position) {
    for (vector_t trace : this->trace) {
        glPushMatrix();
        {
            glTranslatef(trace.x + position.x, trace.y + position.y, trace.z + position.z);
            glutSolidSphere(0.01, 50, 50);
        }
        glPopMatrix();
    }
}

void Particle::setAcceleration(vector_t acceleration) {
    this->acceleration = acceleration;
}

bool Particle::isLifecycleOut(float dtime) {
    return dtime - this->timestamp >= this->lifecycle;
}

vector_t Particle::getPosition() {
    return this->position;
}

void Particle::setIsAttracted() {
    this->lifecycle += 30;
    this->isAttracted = true;
}

void Particle::addCurrentPositionToTrace() {
    if (this->trace.size() == TRACE_LENGTH) {
        this->trace.pop_back();
    }
    this->trace.push_front({this->position.x, this->position.y, this->position.z});
}

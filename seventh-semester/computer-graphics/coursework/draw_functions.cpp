#include <random>

#include "include/draw_functions.hpp"
#include "include/particle.hpp"
#include "include/functions.hpp"
#include "include/glut_functions.hpp"
#include "include/constants.hpp"
#include "include/types.hpp"
#include "include/constants.hpp"

#include <glut.h>

void drawParticles(vector_t position, float dtime) {
    for (Particle &particle : particles) {
        if (particle.isLifecycleOut(dtime)) {
            particle = Particle({getRandomNumber(MIN_ACCELERATION_VALUE, MAX_ACCELERATION_VALUE),
                                 getRandomNumber(MIN_ACCELERATION_VALUE, MAX_ACCELERATION_VALUE),
                                 getRandomNumber(MIN_ACCELERATION_VALUE, MAX_ACCELERATION_VALUE)},
                                 getRandomNumber(MIN_LIFECYCLE_VALUE, MAX_LIFECYCLE_VALUE), dtime);
        }

        if (attractor.isAttracted(particle.getPosition())) {
            vector_t attractorPos = attractor.getPosition();
            vector_t newAcceleration = {((float) 1.0 + attractorPos.x - particle.getPosition().x) / (float) 100.0,
                                        0.0,
                                        (attractorPos.z - particle.getPosition().z) / (float) 100.0};
            particle.setAcceleration(newAcceleration);
            particle.setIsAttracted();
        }

        particle.draw(position, dtime);
    }
}

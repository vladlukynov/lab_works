#include <random>
#include <vector>
#include <ctime>
#include <iostream>

#include "include/glut_functions.hpp"
#include "include/draw_functions.hpp"
#include "include/functions.hpp"
#include "include/particle.hpp"
#include "include/attractor.hpp"
#include "include/constants.hpp"

#include <glut.h>

std::vector<Particle> particles;
Attractor attractor({1.0, 0.0, 0.0}, 0.5, 0.25, 0.5);

float cameraAngle = 0.0;

void createLight() {
    GLfloat position[] = {0.0, 2.0, 0.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light);
}

void initGlutFunctions(int particlesCount) {
    float dtime = std::clock() / (float) CLOCKS_PER_SEC;

    for (int i = 0; i < particlesCount; i++) {
        particles.push_back(Particle({getRandomNumber(MIN_ACCELERATION_VALUE, MAX_ACCELERATION_VALUE),
                                      getRandomNumber(MIN_ACCELERATION_VALUE, MAX_ACCELERATION_VALUE),
                                      getRandomNumber(MIN_ACCELERATION_VALUE, MAX_ACCELERATION_VALUE)},
                                      getRandomNumber(MIN_LIFECYCLE_VALUE, MAX_LIFECYCLE_VALUE), dtime));
    }
    createLight();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float dtime = std::clock() / (float) CLOCKS_PER_SEC;

    glPushMatrix();
    {
        glTranslatef(0.0, 0.0, -5.0);
        glRotatef(cameraAngle, 1.0, 1.0, 0.0);

        drawParticles({-1.0, 0.0, 0.0}, dtime);
        attractor.draw();
    }
    glPopMatrix();

    glFlush();
    glutPostRedisplay();
}

void handleKeys(unsigned char key, int, int) {
    if (key == ENTER_KEY) {
        cameraAngle = cameraAngle == 0.0 ? 45.0 : 0.0;
    }
}

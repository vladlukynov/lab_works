#ifndef GLUT_FUNCTIONS_HPP
#define GLUT_FUNCTIONS_HPP

#include <vector>

#include "particle.hpp"

extern std::vector<Particle> particles;

void display();
void initGlutFunctions(int particlesCount);
void handleKeys(unsigned char key, int , int );

#endif

#include "include/functions.hpp"

#include <random>

float getRandomNumber(float a, float b) {
    std::random_device randomDevice;
    std::mt19937 mt19937(randomDevice());
    std::uniform_real_distribution<float> randomizer(a, b);
    
    return randomizer(mt19937);
}

#include "utility.h"

// Functions
float randomFloat() {
    // Random number from [0, 1)
    return rand() / (RAND_MAX + 1.0);
}

float randomFloat(float min, float max) {
    // Random number from [min, max)
    return min + (max-min)*randomFloat();
}

float degreesToRadians(float degrees) {
    return degrees * pi / 180.0;
}
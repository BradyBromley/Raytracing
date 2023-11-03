#ifndef UTILITY_H
#define UTILITY_H

// Headers
#include <limits>
#include <random>

// Using
using namespace std;

// Constants
const int maxColour = 255;
const float infinity = numeric_limits<float>::infinity();
const float pi = 3.14159265358979;

// Functions
float randomFloat();
float randomFloat(float min, float max);

#endif
#ifndef RAYTRACER_FUNCTIONS_H
#define RAYTRACER_FUNCTIONS_H

#include <fstream>
#include "vec3.h"
#include "ray.h"

using namespace std;

Colour3 rayColour(Ray r);

void writeColour(ofstream &imageFile, Colour3 pixelColour);

void render();



#endif
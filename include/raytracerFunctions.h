#ifndef RAYTRACER_FUNCTIONS_H
#define RAYTRACER_FUNCTIONS_H

// Headers
#include <fstream>
#include "constants.h"
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "surface.h"
#include "sphere.h"
#include "surfaceList.h"

// Using
using namespace std;

// Functions
Colour3 rayColour(const Ray &r, const Surface &s);

void writeColour(ofstream &imageFile, const Colour3 &pixelColour);

void render();



#endif
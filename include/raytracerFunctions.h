#ifndef RAYTRACER_FUNCTIONS_H
#define RAYTRACER_FUNCTIONS_H

#include <fstream>
#include "vec3.h"
#include "ray.h"

using namespace std;

bool intersection(const Point3 &sphereCenter, float radius, const Ray &r);

Colour3 rayColour(const Ray &r);

void writeColour(ofstream &imageFile, const Colour3 &pixelColour);

void render();



#endif
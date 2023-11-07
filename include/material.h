#ifndef MATERIAL_H
#define MATERIAL_H

// Headers
#include "ray.h"
#include "hitRecord.h"


// Using
using namespace std;

// Class
class Material {
    public:
        virtual void scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const = 0;

};

#endif
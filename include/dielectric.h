#ifndef DIELECTRIC_H
#define DIELECTRIC_H

// Headers
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "material.h"

// Using
using namespace std;

// Class
class Dielectric : public Material {
    private:
        // The index of refraction (how much it refracts) depends on the material being hit
        float indexOfRefraction;
    public:
        // Constructors
        Dielectric(const float i);

        // Other Methods
        bool scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const override;
};

#endif
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

// Headers
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "material.h"

// Using
using namespace std;

// Class
class Lambertian : public Material {
    private:
        // The albedo is the fraction of light that is reflected
        Colour3 albedo;
    public:
        // Constructors
        Lambertian(const Colour3 &c);

        // Other Methods
        void scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const override;
};

#endif
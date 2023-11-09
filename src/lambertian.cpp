#include "lambertian.h"

// Constructors
Lambertian::Lambertian(const Colour3 &c) {
    albedo = c;
}


// Other Methods
bool Lambertian::scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const {
    // The ray gets reflected in the direction of the surface normal + a random unit vector
    Vec3 scatterDirection = record.normal + Vec3::randomUnitVector();

    if (scatterDirection.nearZero()) {
        scatterDirection = record.normal;
    }

    scatteredRay = Ray(record.point, scatterDirection);
    // Attenuation is the reduction in light intensity of the ray after being reflected
    attenuation = albedo;
    return true;
}
#include "dielectric.h"

// Constructors
Dielectric::Dielectric(const float i) {
    indexOfRefraction = i;
}


// Other Methods
bool Dielectric::scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const {
    // Attenuation is the reduction in light intensity of the ray after being reflected
    attenuation = Colour3(1.0, 1.0, 1.0);

    // The refraction depends on the angle from the incoming ray to the normal, and based on the material
    float refractionRatio = record.frontFace ? (1.0/indexOfRefraction) : indexOfRefraction;
    Vec3 refractionDirection = Vec3::refractedVector(Vec3::unitVector(ray.getDirection()), record.normal, refractionRatio);
    scatteredRay = Ray(record.point, refractionDirection);

    return true;
}
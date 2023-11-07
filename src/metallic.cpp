#include "metallic.h"

// Constructors
Metallic::Metallic(const Colour3 &c) {
    albedo = c;
}


// Other Methods
void Metallic::scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const {
    // The ray gets reflected at the same angle it arrived at (mirrored around the normal vector)
    Vec3 reflectionDirection = Vec3::reflectedVector(Vec3::unitVector(ray.getDirection()), record.normal);

    scatteredRay = Ray(record.point, reflectionDirection);
    // Attenuation is the reduction in light intensity of the ray after being reflected
    attenuation = albedo;
    return;
}
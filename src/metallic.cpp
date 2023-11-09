#include "metallic.h"

// Constructors
Metallic::Metallic(const Colour3 &c, const float f) {
    albedo = c;
    fuzz = f < 1.0 ? f : 1.0;
}


// Other Methods
bool Metallic::scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const {
    // The ray gets reflected at the same angle it arrived at (mirrored around the normal vector)
    Vec3 reflectionDirection = Vec3::reflectedVector(Vec3::unitVector(ray.getDirection()), record.normal);

    // Adding some randomness to the scattered ray increases the fuzziness of the metal
    scatteredRay = Ray(record.point, reflectionDirection + fuzz*Vec3::randomUnitVector());
    
    // Attenuation is the reduction in light intensity of the ray after being reflected
    attenuation = albedo;

    // Return true if the scattered ray is pointing away from the object
    return Vec3::dot(record.normal, scatteredRay.getDirection()) > 0;
}
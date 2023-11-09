#include "dielectric.h"

// Constructors
Dielectric::Dielectric(const float i) {
    indexOfRefraction = i;
}


// Private Methods
float Dielectric::schlickApproximation(float cos, float refractionRatio) {
    float r0 = (1.0 - refractionRatio) / (1.0 + refractionRatio);
    r0 = r0*r0;
    return r0 + (1.0 - r0)*pow((1.0 - cos), 5);
}


// Other Methods
bool Dielectric::scatter(const Ray &ray, const HitRecord &record, Colour3 &attenuation, Ray &scatteredRay) const {
    // Attenuation is the reduction in light intensity of the ray after being reflected
    attenuation = Colour3(1.0, 1.0, 1.0);

    // The refraction depends on the angle from the incoming ray to the normal, and based on the material
    float refractionRatio = record.frontFace ? (1.0/indexOfRefraction) : indexOfRefraction;

    Vec3 unitDirection = Vec3::unitVector(ray.getDirection());

    float cosTheta = fmin(Vec3::dot(-unitDirection, record.normal), 1.0);
    float sinTheta = sqrt(1.0 - cosTheta*cosTheta);
    bool cannotRefract = refractionRatio * sinTheta > 1.0;
    bool schlickApproximationLarge = schlickApproximation(cosTheta, refractionRatio) > randomFloat();

    Vec3 direction;

    if (cannotRefract || schlickApproximationLarge) {
        // If this expression is true, Snell's law doesn't hold so refraction isn't possible
        // Or, Schlick's approximation is sufficiently large. This depends on the angle that the ray hits the object at
        direction = Vec3::reflectedVector(unitDirection, record.normal);
    } else {
        direction = Vec3::refractedVector(unitDirection, record.normal, refractionRatio);
    }
    scatteredRay = Ray(record.point, direction);

    return true;
}
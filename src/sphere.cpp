#include <cmath>
#include "sphere.h"


// Constructors
Sphere::Sphere() {
    center = Point3();
    radius = 1.0;
}

Sphere::Sphere(const Point3 &c, float r) {
    center = c;
    radius = r;
}


// Getters
Point3 Sphere::getCenter() const {
    return center;
}

float Sphere::getRadius() const {
    return radius;
}


// Other Methods
bool Sphere::intersect(const Ray &r, float tMin, float tMax, HitRecord &record) {
    Vec3 rayPointMinusSphereCenter = r.getPoint() - center;

    // Get a,b,c values for the quadratic equation
    // a dot product of a vector with itself is the length squared
    // If b = 2*halfB, then 2's can be factored out of the quadratic equation
    float a = r.getDirection().lengthSquared();
    float halfB = dot(r.getDirection(), rayPointMinusSphereCenter);
    float c = rayPointMinusSphereCenter.lengthSquared() - (radius * radius);
    float discriminant = (halfB * halfB) - (a * c);

    // The sphere isn't intersected if there are no real roots
    if (discriminant < 0) {
        return false;
    }

    // The sphere doesn't count as being intersected if the t value is out of range
    float discriminantSqrt = sqrt(discriminant);
    float smallestRoot = (-halfB - discriminantSqrt) / a;
    if ((smallestRoot < tMin) || (smallestRoot > tMax)) {
        smallestRoot = (-halfB + discriminantSqrt) / a;
        if ((smallestRoot < tMin) || (smallestRoot > tMax)) {
            return false;
        }
    }

    // Record where the ray hit, the normal at that point, and the t value used
    record.point = r.at(smallestRoot);
    record.normal = unitVector(r.at(smallestRoot) - center);
    record.t = smallestRoot;

    return true;
}

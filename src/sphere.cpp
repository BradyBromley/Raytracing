#include <cmath>
#include "sphere.h"


// Constructors
Sphere::Sphere() {
    center = Point3(0.0, 0.0, 0.0);
    radius = 1.0;
}

Sphere::Sphere(const Point3 &c, float r, shared_ptr<Material> m) {
    center = c;
    radius = r;
    material = m;
}


// Other Methods
bool Sphere::intersect(const Ray &r, Interval interval, HitRecord &record) const {
    Vec3 rayPointMinusSphereCenter = r.getPoint() - center;

    // Get a,b,c values for the quadratic equation
    // a dot product of a vector with itself is the length squared
    // If b = 2*halfB, then 2's can be factored out of the quadratic equation
    float a = r.getDirection().lengthSquared();
    float halfB = Vec3::dot(rayPointMinusSphereCenter, r.getDirection());
    float c = rayPointMinusSphereCenter.lengthSquared() - (radius * radius);
    float discriminant = (halfB * halfB) - (a * c);

    // The sphere isn't intersected if there are no real roots
    if (discriminant < 0) {
        return false;
    }

    // The sphere doesn't count as being intersected outside of the interval
    float discriminantSqrt = sqrt(discriminant);
    float smallestRoot = (-halfB - discriminantSqrt) / a;
    if (!interval.surrounds(smallestRoot)) {
        smallestRoot = (-halfB + discriminantSqrt) / a;
        if (!interval.surrounds(smallestRoot)) {
            return false;
        }
    }

    // Record where the ray hit, the normal at that point, and the t value used
    record.t = smallestRoot;
    record.point = r.at(smallestRoot);
    record.setFaceNormal(r, (record.point - center) / radius);
    record.material = material;

    return true;
}

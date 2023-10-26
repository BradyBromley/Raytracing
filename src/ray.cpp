#include "ray.h"

// Constructors
Ray::Ray() {
}

Ray::Ray(const Point3 &p, const Vec3 &d) {
    point = p;
    direction = d;
}


// Getters
Point3 Ray::getPoint() const {
    return point;
}

Vec3 Ray::getDirection() const {
    return direction;
}


// Other Methods
Point3 Ray::at(float t) const {
    return point + t*direction;
}
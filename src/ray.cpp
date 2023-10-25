#include "ray.h"

// Constructors
Ray::Ray() {
}

Ray::Ray(Point3 p, Vec3 d) {
    point = p;
    direction = d;
}

// Getters
Point3 Ray::getPoint() {
    return point;
}

Vec3 Ray::getDirection() {
    return direction;
}

// Other Methods
Point3 Ray::at(float t) {
    return point + direction*t;
}
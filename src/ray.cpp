#include "ray.h"

// Constructors
Ray::Ray() {
}

Ray::Ray(Vec3 p, Vec3 d) {
    point = p;
    direction = d;
}

Vec3 Ray::at(float t) {
    return point + direction*t;
}
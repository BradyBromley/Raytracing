#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    private:
        Point3 point;
        Vec3 direction;
    public:

        // Constructors
        Ray();
        Ray(Point3 p, Vec3 d);

        // Getters
        Point3 getPoint();
        Vec3 getDirection();

        // Methods
        Point3 at(float t);

};

#endif
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
        Ray(const Point3 &p, const Vec3 &d);

        // Getters
        Point3 getPoint() const;
        Vec3 getDirection() const;

        // Other Methods
        Point3 at(float t) const;

};

#endif
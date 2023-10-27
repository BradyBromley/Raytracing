#ifndef SURFACE_H
#define SURFACE_H

#include "ray.h"

class HitRecord {
    public:
        Point3 point;
        Vec3 normal;
        float t;
};

class Surface {
    public:
        virtual bool intersect(const Ray &r, float tMin, float tMax, HitRecord &record) = 0;
};

#endif
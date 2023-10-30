#ifndef SURFACE_H
#define SURFACE_H

#include "ray.h"
#include "hitRecord.h"

class Surface {
    public:
        virtual bool intersect(const Ray &r, float tMin, float tMax, HitRecord &record) = 0;
};

#endif
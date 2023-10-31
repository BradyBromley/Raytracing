#ifndef SURFACE_H
#define SURFACE_H

// Headers
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "interval.h"

// Using
using namespace std;

// Class
class Surface {
    public:
        virtual bool intersect(const Ray &r, Interval interval, HitRecord &record) const = 0;
};

#endif
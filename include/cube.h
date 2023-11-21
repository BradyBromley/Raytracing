#ifndef CUBE_H
#define CUBE_H

// Headers
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "surface.h"
#include "interval.h"
#include "material.h"

// Using
using namespace std;

// Class
class Cube : public Surface {
    private:
        Point3 minCorner;
        Point3 maxCorner;
        shared_ptr<Material> material;
    public:

        // Constructors
        Cube();
        Cube(const Point3 &center, float halfWidth, shared_ptr<Material> m);

        // Other Methods
        bool intersect(const Ray &r, Interval interval, HitRecord &record) const override;
};

#endif
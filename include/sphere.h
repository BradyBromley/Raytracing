#ifndef SPHERE_H
#define SPHERE_H

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
class Sphere : public Surface {
    private:
        Point3 center;
        float radius;
        shared_ptr<Material> material;
    public:

        // Constructors
        Sphere();
        Sphere(const Point3 &c, float r, shared_ptr<Material> m);

        // Other Methods
        bool intersect(const Ray &r, Interval interval, HitRecord &record) const override;
};

#endif
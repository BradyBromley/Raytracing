#ifndef SPHERE_H
#define SPHERE_H

// Headers
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "surface.h"
#include "interval.h"

// Using
using namespace std;

// Class
class Sphere : public Surface {
    private:
        Point3 center;
        float radius;
    public:

        // Constructors
        Sphere();
        Sphere(const Point3 &c, float r);

        // Getters
        Point3 getCenter() const;
        float getRadius() const;

        // Other Methods
        bool intersect(const Ray &r, Interval interval, HitRecord &record) const override;
};

#endif
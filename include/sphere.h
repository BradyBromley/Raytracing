#ifndef SPHERE_H
#define SPHERE_H

#include "surface.h"

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
        bool intersect(const Ray &r, float tMin, float tMax, HitRecord &record) override;
};

#endif
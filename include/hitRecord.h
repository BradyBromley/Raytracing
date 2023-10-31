#ifndef HITRECORD_H
#define HITRECORD_H

// Headers
#include "vec3.h"
#include "ray.h"

// Using
using namespace std;

// Class
class HitRecord {
    public:
        float t;
        Point3 point;
        Vec3 normal;
        bool frontFace;

        void setFaceNormal(const Ray &r, const Vec3 &outwardNormal);
};

#endif
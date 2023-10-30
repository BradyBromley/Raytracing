#ifndef HITRECORD_H
#define HITRECORD_H

#include "ray.h"

class HitRecord {
    public:
        float t;
        Point3 point;
        Vec3 normal;
        bool frontFace;

        void setFaceNormal(const Ray &r, const Vec3 &outwardNormal);
};

#endif
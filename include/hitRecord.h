#ifndef HITRECORD_H
#define HITRECORD_H

class Material;

// Headers
#include <memory>
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
        shared_ptr<Material> material;

        void setFaceNormal(const Ray &r, const Vec3 &outwardNormal);
};

#endif
#include "hitRecord.h"

void HitRecord::setFaceNormal(const Ray &r, const Vec3 &outwardNormal) {
    frontFace = Vec3::dot(r.getDirection(), outwardNormal) < 0.0;
    normal = frontFace ? outwardNormal : -outwardNormal;
}
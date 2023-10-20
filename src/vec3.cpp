#include "vec3.h"

// Constructors
Vec3::Vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

Vec3::Vec3(float x, float y, float z) {
    e[0] = x;
    e[1] = y;
    e[2] = z;
}


// Getter Methods
float Vec3::getX() {
    return e[0];
}

float Vec3::getY() {
    return e[1];
}

float Vec3::getZ() {
    return e[2];
}


// Operator Methods
Vec3 Vec3::operator+(const Vec3 &v) {
    Vec3 res;
    res.e[0] = e[0] + v.e[0];
    res.e[1] = e[1] + v.e[1];
    res.e[2] = e[2] + v.e[2];
    return res;
}

Vec3 Vec3::operator-(const Vec3 &v) {
    Vec3 res;
    res.e[0] = e[0] - v.e[0];
    res.e[1] = e[1] - v.e[1];
    res.e[2] = e[2] - v.e[2];
    return res;
}

Vec3 Vec3::operator*(const float s) {
    Vec3 res;
    res.e[0] = e[0] * s;
    res.e[1] = e[1] * s;
    res.e[2] = e[2] * s;
    return res;
}

Vec3 Vec3::operator/(const float s) {
    Vec3 res;
    res.e[0] = e[0] / s;
    res.e[1] = e[1] / s;
    res.e[2] = e[2] / s;
    return res;
}

float Vec3::dot(const Vec3 &v) {
    float res;
    res = e[0] * v.e[0]
    + e[1] * v.e[1]
    + e[2] * v.e[2];
    return res;
}

Vec3 Vec3::cross(const Vec3 &v) {
    Vec3 res;
    res.e[0] = e[1] * v.e[2] - e[2] * v.e[1];
    res.e[1] = e[2] * v.e[0] - e[0] * v.e[2];
    res.e[2] = e[0] * v.e[1] - e[1] * v.e[0];
    return res;
}
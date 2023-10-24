#include "vec3.h"
#include <cmath>

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


// Getters
float Vec3::getX() {
    return e[0];
}

float Vec3::getY() {
    return e[1];
}

float Vec3::getZ() {
    return e[2];
}

float Vec3::operator[](const int i) {
    return e[i];
}

// Vector Operations
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

Vec3 Vec3::operator*(const Vec3 &v) {
    Vec3 res;
    res.e[0] = e[0] * v.e[0];
    res.e[1] = e[1] * v.e[1];
    res.e[2] = e[2] * v.e[2];
    return res;
}

Vec3 Vec3::operator/(const float s) {
    Vec3 res;
    res.e[0] = e[0] / s;
    res.e[1] = e[1] / s;
    res.e[2] = e[2] / s;
    return res;
}

Vec3 Vec3::operator+=(const Vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vec3 Vec3::operator-=(const Vec3 &v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

Vec3 Vec3::operator*=(const float s) {
    e[0] *= s;
    e[1] *= s;
    e[2] *= s;
    return *this;
}

Vec3 Vec3::operator*=(const Vec3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

Vec3 Vec3::operator/=(const float s) {
    e[0] /= s;
    e[1] /= s;
    e[2] /= s;
    return *this;
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


// Other Methods
float Vec3::lengthSquared() {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

float Vec3::length() {
    return sqrt(lengthSquared());
}

Vec3 Vec3::unitVector() {
    return *this / (*this).length();
}


// The non-member function << needs access to Vec3's private members
ostream& operator<<(ostream &stream, Vec3 &v) {
    stream << v.getX() << ' ' << v.getY() << ' ' << v.getZ() << endl;
    return stream;
}
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
float Vec3::getX() const {
    return e[0];
}

float Vec3::getY() const {
    return e[1];
}

float Vec3::getZ() const {
    return e[2];
}


// Vector Operations
float Vec3::operator[](const int i) {
    return e[i];
}

Vec3 Vec3::operator-() const {
    return Vec3(-e[0], -e[1], -e[2]);
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

Vec3 Vec3::operator*=(float s) {
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

Vec3 Vec3::operator/=(float s) {
    e[0] /= s;
    e[1] /= s;
    e[2] /= s;
    return *this;
}


// Other Methods
float Vec3::lengthSquared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

float Vec3::length() const {
    return sqrt(lengthSquared());
}

bool Vec3::nearZero() const {
    return (fabs(e[0]) < 1e-8) && (fabs(e[1]) < 1e-8) && (fabs(e[2]) < 1e-8);
}

Vec3 Vec3::randomVector() {
    return Vec3(randomFloat(), randomFloat(), randomFloat());
}

Vec3 Vec3::randomVector(float min, float max) {
    return Vec3(randomFloat(min, max), randomFloat(min, max), randomFloat(min, max));
}

float Vec3::dot(const Vec3 &u, const Vec3 &v) {
    return u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ();
}

Vec3 Vec3::cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.getY() * v.getZ() - u.getZ() * v.getY(), u.getZ() * v.getX() - u.getX() * v.getZ(), u.getX() * v.getY() - u.getY() * v.getX());
}

Vec3 Vec3::unitVector(const Vec3 &v) {
    return v / v.length();
}

Vec3 Vec3::randomUnitVector() {
    return unitVector(randomVector(-1, 1));
}

Vec3 Vec3::reflectedVector(const Vec3 &v, const Vec3 &n) {
    return v - 2*(dot(v, n))*n;
}


// The non-member function << needs access to Vec3's private members
ostream& operator<<(ostream &stream, Vec3 &v) {
    stream << v.getX() << ' ' << v.getY() << ' ' << v.getZ() << endl;
    return stream;
}


// These operators need to have proper type conversions on the lhs
Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

Vec3 operator*(const Vec3 &v, float s) {
    return Vec3(v.e[0] * s, v.e[1] * s, v.e[2] * s);
}

Vec3 operator*(float s, const Vec3 &v) {
    return v * s;
}

Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

Vec3 operator/(const Vec3 &v, float s) {
    return Vec3(v.e[0] / s, v.e[1] / s, v.e[2] / s);
}
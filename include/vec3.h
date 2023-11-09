#ifndef VEC3_H
#define VEC3_H

// Headers
#include <iostream>
#include "utility.h"

// Using
using namespace std;

// Class
class Vec3 {
    private:
        float e[3];
    public:

        // Constructors
        Vec3();
        Vec3(float x, float y, float z);

        // Getters
        float getX() const;
        float getY() const;
        float getZ() const;

        // Vector Operations
        float operator[](int i);
        Vec3 operator-() const;
        Vec3 operator+=(const Vec3 &v);
        Vec3 operator-=(const Vec3 &v);
        Vec3 operator*=(float s);
        Vec3 operator*=(const Vec3 &v);
        Vec3 operator/=(float s);

        // Other Methods
        float lengthSquared() const;
        float length() const;
        bool nearZero() const;
        static Vec3 randomVector();
        static Vec3 randomVector(float min, float max);
        static float dot(const Vec3 &u, const Vec3 &v);
        static Vec3 cross(const Vec3 &u, const Vec3 &v);
        static Vec3 unitVector(const Vec3 &v);
        static Vec3 randomUnitVector();
        static Vec3 reflectedVector(const Vec3 &v, const Vec3 &n);
        static Vec3 refractedVector(const Vec3 &v, const Vec3 &n, const float etaOverEtaPrime);
        
        // The non-member function << needs access to Vec3's private members
        friend ostream& operator<<(ostream &stream, Vec3 &v);

        // These operators need to have proper type conversions on the lhs
        Vec3 friend operator+(const Vec3 &u, const Vec3 &v);
        Vec3 friend operator-(const Vec3 &u, const Vec3 &v);
        Vec3 friend operator*(float s, const Vec3 &v);
        Vec3 friend operator*(const Vec3 &v, float s);
        Vec3 friend operator*(const Vec3 &u, const Vec3 &v);
        Vec3 friend operator/(const Vec3 &v, float s);
};

// Aliases
using Point3 = Vec3;
using Colour3 = Vec3;

#endif
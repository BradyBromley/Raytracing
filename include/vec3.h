#ifndef VEC3_H
#define VEC3_H

#include <iostream>
using namespace std;

class Vec3 {
    private:
        float e[3];
    public:

        // Constructors
        Vec3();
        Vec3(float x, float y, float z);

        // Getters
        float getX();
        float getY();
        float getZ();
        float operator[](int i);

        // Vector Operations
        Vec3 operator+(const Vec3 &v);
        Vec3 operator-(const Vec3 &v);
        Vec3 operator*(const float s);
        Vec3 operator*(const Vec3 &v);
        Vec3 operator/(const float s);
        Vec3 operator+=(const Vec3 &v);
        Vec3 operator-=(const Vec3 &v);
        Vec3 operator*=(const float s);
        Vec3 operator*=(const Vec3 &v);
        Vec3 operator/=(const float s);
        
        float dot(const Vec3 &v);
        Vec3 cross(const Vec3 &v);

        // Other Methods
        float lengthSquared();
        float length();
        Vec3 unitVector();

        // The non-member function << needs access to Vec3's private members
        friend ostream& operator<<(ostream &stream, Vec3 &v);
};

// Different aliases for clarity
using Point3 = Vec3;
using Colour3 = Vec3;

#endif
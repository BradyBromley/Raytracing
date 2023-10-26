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
        float getX() const;
        float getY() const;
        float getZ() const;
        float operator[](int i);

        // Vector Operations
        Vec3 operator+=(const Vec3 &v);
        Vec3 operator-=(const Vec3 &v);
        Vec3 operator*=(float s);
        Vec3 operator*=(const Vec3 &v);
        Vec3 operator/=(float s);

        // Other Methods
        float lengthSquared() const;
        float length() const;

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

// Different aliases for clarity
using Point3 = Vec3;
using Colour3 = Vec3;

// Other non-member functions
float dot(const Vec3 &u, const Vec3 &v);
Vec3 cross(const Vec3 &u, const Vec3 &v);
Vec3 unitVector(const Vec3 &v);

#endif
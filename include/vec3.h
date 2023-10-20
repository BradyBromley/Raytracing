#ifndef VEC3_H
#define VEC3_H

class Vec3 {
    public:
        float e[3];

        // Constructors
        Vec3();
        Vec3(float x, float y, float z);

        // Getters
        float getX();
        float getY();
        float getZ();

        // Vector Operations
        Vec3 operator+(const Vec3 &v);
        Vec3 operator-(const Vec3 &v);
        Vec3 operator*(const float s);
        Vec3 operator/(const float s);

        float dot(const Vec3 &v);
        Vec3 cross(const Vec3 &v);
};

#endif
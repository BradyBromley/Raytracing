#include "raytracer.h"
#include "vec3.h"
#include <iostream>

int main() {
    render();

    Vec3 v1(4,5,6);
    Vec3 v2(10,20,30);
    Vec3 v3 = v1 + v2;
    Vec3 v4 = v1 - v2;
    Vec3 v5 = v1 * 10;
    Vec3 v6 = v1 / 10;
    float v7 = v1.dot(v2);
    Vec3 v8 = v1.cross(v2);
    std::cout << v3.getX() << v3.getY() << v3.getZ() << std::endl;
    std::cout << v4.getX() << v4.getY() << v4.getZ() << std::endl;
    std::cout << v5.getX() << v5.getY() << v5.getZ() << std::endl;
    std::cout << v6.getX() << v6.getY() << v6.getZ() << std::endl;
    std::cout << v7 << std::endl;
    std::cout << v8.getX() << v8.getY() << v8.getZ() << std::endl;

    return 0;
}
#include "raytracerFunctions.h"
#include "vec3.h"
#include <iostream>

int main() {
    render();

    Vec3 v1(4,5,6);
    Vec3 v2(10,20,30);
    std::cout << v1.getX() << v1.getY() << v1.getZ() << std::endl;
    std::cout << v2.getX() << v2.getY() << v2.getZ() << std::endl;

    return 0;
}
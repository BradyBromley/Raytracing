#include <iostream>
#include "raytracerFunctions.h"
#include "vec3.h"
#include "ray.h"
using namespace std;

int main() {
    render();

    Vec3 v1(4,5,6);
    Vec3 v2(10,20,30);
    cout << v1;
    cout << v2;

    Ray r1;
    Ray r2(v1, v2);
    Vec3 v3 = r1.at(1);
    Vec3 v4 = r2.at(1);
    cout << v3;
    cout << v4;

    return 0;
}
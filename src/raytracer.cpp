#include <iostream>
#include "utility.h"
#include "vec3.h"
#include "ray.h"
#include "camera.h"

#include "surface.h"
#include "sphere.h"
#include "surfaceList.h"

#include "material.h"
#include "lambertian.h"
#include "metallic.h"

using namespace std;

int main() {

    // Materials
    shared_ptr<Lambertian> material_ground = make_shared<Lambertian>(Colour3(0.3, 0.3, 0.1));
    shared_ptr<Lambertian> material_center = make_shared<Lambertian>(Colour3(0.7, 0.3, 0.3));
    shared_ptr<Metallic> material_left = make_shared<Metallic>(Colour3(0.8, 0.8, 0.8), 0.3);
    shared_ptr<Metallic> material_right = make_shared<Metallic>(Colour3(0.8, 0.6, 0.2), 1.0);


    // Surface
    SurfaceList sList;
    sList.add(make_shared<Sphere>(Point3(0.0,-100.5,-1.0), 100.0, material_ground));
    sList.add(make_shared<Sphere>(Point3(0.0,0.0,-1.0), 0.5, material_center));
    sList.add(make_shared<Sphere>(Point3(-1.0,0.0,-1.0), 0.5, material_left));
    sList.add(make_shared<Sphere>(Point3(1.0,0.0,-1.0), 0.5, material_right));

    Camera camera(16.0 / 9.0, 400, 2.0, 1.0, Point3(0, 0, 0), 100, 50);
    camera.render(sList);

    Point3 v1(4,5,6);
    Point3 v2(10,20,30);
    cout << v1;
    cout << v2;

    Ray r1;
    Ray r2(v1, v2);
    Vec3 v3 = r1.at(1);
    Vec3 v4 = r2.at(1);
    cout << v3;
    cout << v4;

    cout << randomFloat() << endl;
    cout << randomFloat() << endl;

    return 0;
}
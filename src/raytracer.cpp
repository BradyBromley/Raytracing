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
#include "dielectric.h"

using namespace std;

int main() {
    
    // Surface
    SurfaceList sList;

    // Create the ground
    shared_ptr<Lambertian> materialGround = make_shared<Lambertian>(Colour3(0.5, 0.5, 0.5));
    sList.add(make_shared<Sphere>(Point3(0, -1000, 0), 1000, materialGround));

    // Create many small spheres
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            float chooseMat = randomFloat();
            Point3 center(a + 0.9*randomFloat(), 0.2, b + 0.9*randomFloat());

            if ((center - Point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<Material> material;

                if (chooseMat < 0.8) {
                    // Lambertian
                    material = make_shared<Lambertian>(Colour3::randomVector() * Colour3::randomVector());
                    sList.add(make_shared<Sphere>(center, 0.2, material));
                } else if (chooseMat < 0.95) {
                    // Metallic
                    material = make_shared<Metallic>(Colour3::randomVector(0.5, 1), randomFloat(0, 0.5));
                    sList.add(make_shared<Sphere>(center, 0.2, material));
                } else {
                    // Dielectric
                    material = make_shared<Dielectric>(1.5);
                    sList.add(make_shared<Sphere>(center, 0.2, material));
                }
            }
        }
    }

    // Create three large spheres
    shared_ptr<Lambertian> materialLambertian = make_shared<Lambertian>(Colour3(0.4, 0.2, 0.1));
    sList.add(make_shared<Sphere>(Point3(-4, 1, 0), 1.0, materialLambertian));

    shared_ptr<Metallic> materialMetallic = make_shared<Metallic>(Colour3(0.7, 0.6, 0.5), 0.6);
    sList.add(make_shared<Sphere>(Point3(4, 1, 0), 1.0, materialMetallic));

    shared_ptr<Dielectric> materialDielectric = make_shared<Dielectric>(1.5);
    sList.add(make_shared<Sphere>(Point3(0, 1, 0), 1.0, materialDielectric));

    Camera camera(16.0 / 9.0, 1200, 20, 50, 20, Point3(13, 2, 3), Point3(0,0,0), Vec3(0,1,0), 0.6, 10.0);
    camera.render(sList);

    return 0;
}
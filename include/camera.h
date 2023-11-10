#ifndef CAMERA_H
#define CAMERA_H

// Headers
#include <iostream>
#include <fstream>
#include "utility.h"
#include "vec3.h"
#include "ray.h"
#include "hitRecord.h"
#include "surface.h"
#include "material.h"

// Using
using namespace std;

// Class
class Camera {
    private:
        float aspectRatio;
        int imageWidth, imageHeight;
        int samplesPerPixel;
        int maxDepth;
        float verticalFov;

        Point3 cameraLocation;
        Point3 targetLocation;
        Vec3 viewUp;

        Point3 pixelOrigin;
        Vec3 pixelU, pixelV;
        Vec3 u, v, w;

        float defocusAngle;
        float focusDistance;
        Vec3 defocusDiskU, defocusDiskV;

        // Private Methods
        void initialize();
        Colour3 rayColour(const Ray &r, const Surface &s, int depth);
        float linearToGamma(float linearComponent);
        void writeColour(ofstream &imageFile, const Colour3 &pixelColour);
        Vec3 pixelSampleSquare() const;
        Point3 defocusDiskSample() const;
        Ray getRay(int i, int j) const;

    public:
        // Constructors
        Camera(float aRatio = 1.0, int iWidth = 100, int samples = 10,
            int depth = 10, float fov = 90, Point3 center = Point3(0,0,-1),
            Point3 target = Point3(0,0,0), Vec3 vUp = Vec3(0,1,0),
            float angle = 0, float distance = 10);

        // Public Methods
        void render(const Surface &surface);

};

#endif
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
#include "sphere.h"
#include "surfaceList.h"

// Using
using namespace std;

// Class
class Camera {
    private:
        float aspectRatio;
        int imageWidth, imageHeight;
        float viewportWidth, viewportHeight;
        float focalLength;
        Point3 cameraCenter;
        Vec3 viewportU, viewportV;
        Vec3 pixelU, pixelV;
        Point3 pixelOrigin;
        int samplesPerPixel;
        int maxDepth;

        // Private Methods
        void initialize();
        Colour3 rayColour(const Ray &r, const Surface &s, int depth);
        float linearToGamma(float linearComponent);
        void writeColour(ofstream &imageFile, const Colour3 &pixelColour);
        Vec3 pixelSampleSquare() const;
        Ray getRay(int i, int j) const;

    public:
        // Constructors
        Camera(float aRatio = 1.0, int iWidth = 100, float vHeight = 2.0,
            float fLength = 1.0, Point3 cCenter = Point3(0,0,0),
            int samples = 10, int depth = 10);

        // Public Methods
        void render(const Surface &surface);

};

#endif
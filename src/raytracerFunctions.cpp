#include <iostream>
#include <fstream>
#include <cmath>
#include "raytracerFunctions.h"

// The output is a colour value from [0,0,0] to [1,1,1]
Colour3 rayColour(const Ray &r, const Surface &s) {
    
    // Check if the ray hits the surface
    HitRecord record;
    if (s.intersect(r, Interval(0, infinity), record)) {
        return 0.5 * (record.normal + Colour3(1,1,1));
    }

    Vec3 unitDirection = unitVector(r.getDirection());
    float a = 0.5*(unitDirection.getY() + 1.0);
    return Colour3(1.0, 1.0, 1.0)*(1.0 - a) + Colour3(0.5, 0.7, 1.0)*(a);
}

// Scale colours to the correct size and output them to the image file
void writeColour(ofstream &imageFile, const Colour3 &pixelColour) {
    imageFile << static_cast<int>(maxColour*pixelColour.getX())
    << ' ' << static_cast<int>(maxColour*pixelColour.getY())
    << ' ' << static_cast<int>(maxColour*pixelColour.getZ())
    << '\n';
}

void render() {
    // Setting up the image based on an aspect ratio and a width
    float aspectRatio = 16.0 / 9.0;
    int imageWidth = 400;
    int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    // Surface
    SurfaceList sList;
    sList.add(make_shared<Sphere>(Point3(0,0,-1), 0.5));
    sList.add(make_shared<Sphere>(Point3(0,-100.5,-1), 100));


    // Set up the viewport and the camera in front of it
    float viewportHeight = 2.0;
    float viewportWidth = viewportHeight * (static_cast<float>(imageWidth) / imageHeight);
    float focalLength = 1.0;
    Point3 cameraCenter = Point3(0, 0, 0);

    // These are the vectors across the viewport's edges
    // Since the y-axis for the viewport goes from top to bottom, it is negative
    Vec3 viewportU = Vec3(viewportWidth, 0, 0);
    Vec3 viewportV = Vec3(0, -viewportHeight, 0);

    // These are the vectors across the edges of a single pixel
    Vec3 pixelU = viewportU / imageWidth;
    Vec3 pixelV = viewportV / imageHeight;

    // Calculate the location of the top left pixel (The center of the pixel is needed)
    Point3 viewportOrigin = cameraCenter - (viewportU/2) - (viewportV/2) - Point3(0, 0, focalLength);
    Point3 pixelOrigin = viewportOrigin + (pixelU/2) + (pixelV/2);

    // Open the image file and define ASCII colours, width, height, and max color
    ofstream imageFile;
    imageFile.open("../img/image.ppm");
    imageFile << "P3\n" << imageWidth << ' ' << imageHeight << '\n' << maxColour << '\n';

    // Draw the image
    for (int j = 0; j < imageHeight; j++) {
        clog << "\rScanlines remaining: " << (imageHeight - j) << flush;
        for (int i = 0; i < imageWidth; i++) {
            // Find the ray going from the camera to the pixel
            Point3 pixelCenter = pixelOrigin + (i*pixelU) + (j*pixelV);
            Vec3 rayDirection = pixelCenter - cameraCenter;
            Ray r(cameraCenter, rayDirection);

            writeColour(imageFile, rayColour(r, sList));
        }
    }

    imageFile.close();

    clog << "\rDone.                   \n";

    return;
}
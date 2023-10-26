#include <iostream>
#include <fstream>
#include "raytracerFunctions.h"

using namespace std;

const int MAX_COLOUR = 255;

// Check if a ray intersects with a sphere
bool intersection(const Point3 &sphereCenter, float radius, const Ray &r) {
    Vec3 rayPoint = r.getPoint();
    Vec3 rayDirection = r.getDirection();

    // Get a,b,c values for the quadratic equation
    float a = dot(rayDirection, rayDirection);
    float b = 2 * dot(rayDirection, rayPoint - sphereCenter);
    float c = dot(rayPoint - sphereCenter, rayPoint - sphereCenter) - (radius * radius);
    float discriminant = (b * b) - (4 * a * c);
    return (discriminant >= 0);
}

// Blend the colour based on the height of the y coordinate
// The output is colour values from [0,0,0] to [1,1,1]
Colour3 rayColour(const Ray &r) {
    if (intersection(Point3(0, 0, -1), 0.5, r)) {
        return Colour3(1.0, 0, 0);
    }

    Vec3 unitDirection = unitVector(r.getDirection());
    float a = 0.5*(unitDirection.getY() + 1.0);
    return Colour3(1.0, 1.0, 1.0)*(1.0 - a) + Colour3(0.5, 0.7, 1.0)*(a);
}

// Scale colours to the correct size and output them to the image file
void writeColour(ofstream &imageFile, const Colour3 &pixelColour) {
    imageFile << static_cast<int>(MAX_COLOUR*pixelColour.getX())
    << ' ' << static_cast<int>(MAX_COLOUR*pixelColour.getY())
    << ' ' << static_cast<int>(MAX_COLOUR*pixelColour.getZ())
    << '\n';
}

void render() {
    // Setting up the image based on an aspect ratio and a width
    float aspectRatio = 16.0 / 9.0;
    int imageWidth = 400;
    int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

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
    imageFile << "P3\n" << imageWidth << ' ' << imageHeight << '\n' << MAX_COLOUR << '\n';

    // Draw the image
    for (int j = 0; j < imageHeight; j++) {
        clog << "\rScanlines remaining: " << (imageHeight - j) << flush;
        for (int i = 0; i < imageWidth; i++) {
            // Find the ray going from the camera to the pixel
            Point3 pixelCenter = pixelOrigin + (i*pixelU) + (j*pixelV);
            Vec3 rayDirection = pixelCenter - cameraCenter;
            Ray r(cameraCenter, rayDirection);

            writeColour(imageFile, rayColour(r));
        }
    }

    imageFile.close();

    clog << "\rDone.                   \n";

    return;
}
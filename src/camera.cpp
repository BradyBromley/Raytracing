#include "camera.h"

// Constructors
Camera::Camera() {
    aspectRatio = 1.0;
    imageWidth = 100;
    imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    viewportHeight = 2.0;
    viewportWidth = viewportHeight * (static_cast<float>(imageWidth) / imageHeight);
    focalLength = 1.0;
    cameraCenter = Point3(0, 0, 0);
}

Camera::Camera(float aRatio, int iWidth, float vHeight, float fLength, Point3 cCenter) {
    aspectRatio = aRatio;
    imageWidth = iWidth;
    imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    viewportHeight = vHeight;
    viewportWidth = viewportHeight * (static_cast<float>(imageWidth) / imageHeight);
    focalLength = fLength;
    cameraCenter = cCenter;
}


// Private Methods
void Camera::initialize() {
    // These are the vectors across the viewport's edges
    // Since the y-axis for the viewport goes from top to bottom, it is negative
    viewportU = Vec3(viewportWidth, 0, 0);
    viewportV = Vec3(0, -viewportHeight, 0);

    // These are the vectors across the edges of a single pixel
    pixelU = viewportU / imageWidth;
    pixelV = viewportV / imageHeight;

    // Calculate the location of the top left pixel (The center of the pixel is needed)
    Point3 viewportOrigin = cameraCenter - (viewportU/2) - (viewportV/2) - Point3(0, 0, focalLength);
    pixelOrigin = viewportOrigin + (pixelU/2) + (pixelV/2);
}

Colour3 Camera::rayColour(const Ray &r, const Surface &s) {

    // Colour the ray based on the normal where it intersects the surface
    HitRecord record;
    if (s.intersect(r, Interval(0, infinity), record)) {
        return 0.5 * (record.normal + Colour3(1,1,1));
    }

    // Set the background colour
    Vec3 unitDirection = unitVector(r.getDirection());
    float a = 0.5*(unitDirection.getY() + 1.0);
    return Colour3(1.0, 1.0, 1.0)*(1.0 - a) + Colour3(0.5, 0.7, 1.0)*(a);
}

void Camera::writeColour(ofstream &imageFile, const Colour3 &pixelColour) {
    imageFile << static_cast<int>(maxColour*pixelColour.getX())
    << ' ' << static_cast<int>(maxColour*pixelColour.getY())
    << ' ' << static_cast<int>(maxColour*pixelColour.getZ())
    << '\n';
}


// Public Methods
void Camera::render(const Surface& surface) {
    initialize();

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

            writeColour(imageFile, rayColour(r, surface));
        }
    }

    imageFile.close();

    clog << "\rDone.                   \n";

    return;
}
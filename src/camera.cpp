#include "camera.h"

// Constructors
Camera::Camera(float aRatio, int iWidth, int samples, int depth, float fov, Point3 center, Point3 target, Vec3 vUp, float angle, float distance) {
    aspectRatio = aRatio;
    imageWidth = iWidth;
    samplesPerPixel = samples;
    maxDepth = depth;
    
    // Camera location and orientation
    verticalFov = fov;
    cameraLocation = center;
    targetLocation = target;
    viewUp = vUp;

    defocusAngle = angle;
    focusDistance = distance;
}


// Private Methods
void Camera::initialize() {
    imageHeight = static_cast<int>(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    // Determine viewport dimensions
    float theta = degreesToRadians(verticalFov);
    float h = tan(theta/2);
    float viewportHeight = 2.0 * h * focusDistance;
    float viewportWidth = viewportHeight * (static_cast<float>(imageWidth) / imageHeight);
    
    // Calculate u,v,w unit basis vectors for the camera coordinate frame
    w = Vec3::unitVector(cameraLocation - targetLocation);
    u = Vec3::unitVector(Vec3::cross(viewUp, w));
    v = Vec3::unitVector(Vec3::cross(w, u));

    // These are the vectors across the viewport's edges
    // Since the y-axis for the viewport goes from top to bottom, it is negative
    Vec3 viewportU = viewportWidth * u;
    Vec3 viewportV = viewportHeight * -v;

    // These are the vectors across the edges of a single pixel
    pixelU = viewportU / imageWidth;
    pixelV = viewportV / imageHeight;

    // Calculate the location of the top left pixel (The center of the pixel is needed)
    Point3 viewportOrigin = cameraLocation - (viewportU/2) - (viewportV/2) - (focusDistance * w);
    pixelOrigin = viewportOrigin + (pixelU/2) + (pixelV/2);

    // Calculate the camera defocus disk basis vectors
    float defocusRadius = focusDistance * tan(degreesToRadians(defocusAngle/2));
    defocusDiskU = u * defocusRadius;
    defocusDiskV = v * defocusRadius;
}

Colour3 Camera::rayColour(const Ray &r, const Surface &s, int depth) {

    // Return a black pixel if the max recursion depth is reached
    if (depth <= 0) {
        return Colour3(0.0, 0.0, 0.0);
    }

    // The ray gets its colour by recursively bouncing off of the objects in the scene
    HitRecord record;
    if (s.intersect(r, Interval(0.001, infinity), record)) {
        Colour3 attenuation;
        Ray scatteredRay;
        if (record.material->scatter(r, record, attenuation, scatteredRay)) {
            return attenuation * rayColour(scatteredRay, s, depth - 1);
        }
        return Colour3(0.0, 0.0, 0.0);
    }

    // Set the background colour
    Vec3 unitDirection = Vec3::unitVector(r.getDirection());
    float a = 0.5*(unitDirection.getY() + 1.0);
    return Colour3(1.0, 1.0, 1.0)*(1.0 - a) + Colour3(0.5, 0.7, 1.0)*(a);
}

float Camera::linearToGamma(float linearComponent) {
    // Gamma correct the image
    return sqrt(linearComponent);
}

void Camera::writeColour(ofstream &imageFile, const Colour3 &pixelColour) {
    // Make sure that the colour has values in [0, 1)
    Interval interval(0.000, 0.999);
    float r = interval.clamp(linearToGamma(pixelColour.getX()));
    float g = interval.clamp(linearToGamma(pixelColour.getY()));
    float b = interval.clamp(linearToGamma(pixelColour.getZ()));

    imageFile << static_cast<int>(maxColour*r)
    << ' ' << static_cast<int>(maxColour*g)
    << ' ' << static_cast<int>(maxColour*b)
    << '\n';
}

Vec3 Camera::pixelSampleSquare() const {
    // Take random colour samples from around the pixel
    float x = -0.5 + randomFloat();
    float y = -0.5 + randomFloat();
    return (x*pixelU) + (y*pixelV);
}

Point3 Camera::defocusDiskSample() const {
    // Return a random point in the defocus disk
    Vec3 point = Vec3::randomInUnitDisk();
    Vec3 point2 = cameraLocation + (point[0] * defocusDiskU) + (point[1] * defocusDiskV);
    return cameraLocation + (point[0] * defocusDiskU) + (point[1] * defocusDiskV);
}

Ray Camera::getRay(int i, int j) const {
    // Find the center of the the pixel that the ray goes through
    Point3 pixelCenter = pixelOrigin + (i*pixelU) + (j*pixelV);
    // Add some randomness so that every sample is slightly different
    Point3 pixelSample = pixelCenter + pixelSampleSquare();

    Point3 rayOrigin = (defocusAngle <= 0) ? cameraLocation : defocusDiskSample();
    Vec3 rayDirection = pixelSample - rayOrigin;
    return Ray(rayOrigin, rayDirection);

}


// Public Methods
void Camera::render(const Surface& surface) {
    initialize();

    // Open the image file and define ASCII colours, width, height, and max color
    ofstream imageFile;
    imageFile.open("../images/image.ppm");
    imageFile << "P3\n" << imageWidth << ' ' << imageHeight << '\n' << maxColour << '\n';

    // Draw the image
    for (int j = 0; j < imageHeight; j++) {
        clog << "\rScanlines remaining: " << (imageHeight - j) << flush;
        for (int i = 0; i < imageWidth; i++) {

            // Take random samples around the pixel and average the resulting colour values
            // This is done for anti-aliasing
            Colour3 cumulativeColour(0,0,0);
            for (int sample = 0; sample < samplesPerPixel; ++sample) {
                Ray r = getRay(i, j);
                cumulativeColour += rayColour(r, surface, maxDepth);
            }
            writeColour(imageFile, cumulativeColour/samplesPerPixel);
        }
        
    }

    imageFile.close();

    clog << "\rDone.                   \n";

    return;
}
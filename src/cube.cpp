#include <cmath>
#include "cube.h"


// Constructors
Cube::Cube() {
    minCorner = Point3(0.0, 0.0, 0.0);
    maxCorner = Point3(1.0, 1.0, 1.0);
}

Cube::Cube(const Point3 &center, float halfWidth, shared_ptr<Material> m) {
    minCorner = center - Point3(halfWidth, halfWidth, halfWidth);
    maxCorner = center + Point3(halfWidth, halfWidth, halfWidth);
    material = m;
}


// Other Methods
bool Cube::intersect(const Ray &r, Interval interval, HitRecord &record) const {

    Point3 rayPoint = r.getPoint();
    Vec3 rayDirection = r.getDirection();

    // Consider the six planes that make up a cube
    // Below are the six t values where the ray intersects those planes
    // Set the t values to +-infinity if the direction is 0
    float txMin, txMax;
    if (rayDirection.getX() >= 0) {
        // The first plane that is intersected is the min
        txMin = minCorner.getX() - rayPoint.getX();
        txMax = maxCorner.getX() - rayPoint.getX();
    } else {
        txMin = maxCorner.getX() - rayPoint.getX();
        txMax = minCorner.getX() - rayPoint.getX();
    }
    txMin = rayDirection.getX() == 0 ? -infinity : txMin / rayDirection.getX();
    txMax = rayDirection.getX() == 0 ? infinity : txMax / rayDirection.getX();

    float tyMin, tyMax;
    if (rayDirection.getY() >= 0) {
        tyMin = minCorner.getY() - rayPoint.getY();
        tyMax = maxCorner.getY() - rayPoint.getY();
    } else {
        tyMin = maxCorner.getY() - rayPoint.getY();
        tyMax = minCorner.getY() - rayPoint.getY();
    }
    tyMin = rayDirection.getY() == 0 ? -infinity : tyMin / rayDirection.getY();
    tyMax = rayDirection.getY() == 0 ? infinity : tyMax / rayDirection.getY();

    if ((txMin > tyMax) || (tyMin > txMax)) {
        // If a min is greater than a max for different directions, then the ray doesn't intersect the cube
        return false;
    }

    // The axis for the largest min is needed to determine the normal (X=0, Y=1, Z=2)
    int largestMin;
    // When comparing with z, only the largest min and smallest max are needed
    float tMin, tMax;

    if (txMin > tyMin) {
        tMin = txMin;
        largestMin = 0;
    } else {
        tMin = tyMin;
        largestMin = 1;
    }
    tMax = txMax < tyMax ? txMax : tyMax;

    float tzMin, tzMax;    
    if (rayDirection.getZ() >= 0) {
        tzMin = minCorner.getZ() - rayPoint.getZ();
        tzMax = maxCorner.getZ() - rayPoint.getZ();
    } else {
        tzMin = maxCorner.getZ() - rayPoint.getZ();
        tzMax = minCorner.getZ() - rayPoint.getZ();
    }
    tzMin = rayDirection.getZ() == 0 ? -infinity : tzMin / rayDirection.getZ();
    tzMax = rayDirection.getZ() == 0 ? infinity : tzMax / rayDirection.getZ();

    if ((tzMin > tMax) || (tMin > tzMax)) {
        return false;
    }

    if (tzMin > tMin) {
        tMin = tzMin;
        largestMin = 2;
    }
    tMax = tzMax < tMax ? tzMax : tMax;

    if (!interval.surrounds(tMin)) {
        return false;
    }

    // Find the normal of the intersection point
    Vec3 normal;
    if (largestMin == 0) {
        Vec3 yLine = Point3(minCorner.getX(), maxCorner.getY(), minCorner.getZ()) - minCorner;
        Vec3 zLine = Point3(minCorner.getX(), minCorner.getY(), maxCorner.getZ()) - minCorner;
        normal = Vec3::cross(yLine, zLine);
    } else if (largestMin == 1) {
        Vec3 zLine = Point3(minCorner.getX(), minCorner.getY(), maxCorner.getZ()) - minCorner;
        Vec3 xLine = Point3(maxCorner.getX(), minCorner.getY(), minCorner.getZ()) - minCorner;
        normal = Vec3::cross(zLine, xLine);
    } else {
        Vec3 xLine = Point3(maxCorner.getX(), minCorner.getY(), minCorner.getZ()) - minCorner;
        Vec3 yLine = Point3(minCorner.getX(), maxCorner.getY(), minCorner.getZ()) - minCorner;
        normal = Vec3::cross(xLine, yLine);
    }

    // Make sure the normal is the outside normal
    if (Vec3::dot(rayDirection, normal) >= 0.0) {
        normal = -normal;
    }
    Vec3 unitNormal = Vec3::unitVector(normal);

    // Record where the ray hit, the normal at that point, and the t value used
    record.t = tMin;
    record.point = r.at(tMin);
    record.setFaceNormal(r, unitNormal);
    record.material = material;

    return true;
}

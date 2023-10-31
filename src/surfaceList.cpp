#include "surfaceList.h"


// Constructors
SurfaceList::SurfaceList() {

}

SurfaceList::SurfaceList(shared_ptr<Surface> object) {
    add(object);
}


// Other Methods
void SurfaceList::add(shared_ptr<Surface> object) {
    objects.push_back(object);
}

bool SurfaceList::intersect(const Ray &r, Interval interval, HitRecord &record) const {
    HitRecord tempRecord;
    bool intersectAnything = false;
    float closestObject = interval.max;
    
    // Find the first object that is hit by the ray
    for (shared_ptr<Surface> object : objects) {
        if (object->intersect(r, Interval(interval.min, closestObject), tempRecord)) {
            intersectAnything = true;
            closestObject = tempRecord.t;
            record = tempRecord;
        }
    }

    return intersectAnything;
}
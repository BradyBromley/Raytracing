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

bool SurfaceList::intersect(const Ray &r, float tMin, float tMax, HitRecord &record) {
    HitRecord tempRecord;
    bool intersectAnything = false;
    float closestObject = tMax;
    
    for (shared_ptr<Surface> object : objects) {
        if (object->intersect(r, tMin, closestObject, tempRecord)) {
            intersectAnything = true;
            closestObject = tempRecord.t;
            record = tempRecord;
        }
    }

    return intersectAnything;
}
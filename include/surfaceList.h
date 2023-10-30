#ifndef SURFACE_LIST_H
#define SURFACE_LIST_H

#include <vector>
#include <memory>
#include "surface.h"

class SurfaceList : public Surface {
    public:
        vector<shared_ptr<Surface>> objects;

        // Constructors
        SurfaceList();
        SurfaceList(shared_ptr<Surface> object);

        // Other Methods
        void add(shared_ptr<Surface> object);
        bool intersect(const Ray &r, float tMin, float tMax, HitRecord &record) override;
    
};

#endif
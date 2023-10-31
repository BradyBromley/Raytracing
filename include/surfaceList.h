#ifndef SURFACE_LIST_H
#define SURFACE_LIST_H

// Headers
#include <vector>
#include <memory>
#include "vec3.h"
#include "ray.h"
#include "surface.h"
#include "interval.h"

// Using
using namespace std;

// Class
class SurfaceList : public Surface {
    public:
        vector<shared_ptr<Surface>> objects;

        // Constructors
        SurfaceList();
        SurfaceList(shared_ptr<Surface> object);

        // Other Methods
        void add(shared_ptr<Surface> object);
        bool intersect(const Ray &r, Interval interval, HitRecord &record) const override;
    
};

#endif
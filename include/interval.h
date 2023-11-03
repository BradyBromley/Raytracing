#ifndef INTERVAL_H
#define INTERVAL_H

// Using
using namespace std;

// Class
class Interval {
    public:
        float min;
        float max;

        // Constructors
        Interval();
        Interval(float m, float M);

        // Methods
        bool contains(float value) const;
        bool surrounds(float value) const;
        float clamp(float value) const;
};

#endif
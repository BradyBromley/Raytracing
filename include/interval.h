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
        bool contains(float value);
        bool surrounds(float value);
};

#endif
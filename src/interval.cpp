#include "interval.h"
#include "utility.h"

// Constructors
Interval::Interval() {
    min = -infinity;
    max = infinity;
}

Interval::Interval(float m, float M) {
    min = m;
    max = M;
}


// Methods
bool Interval::contains(float value) const {
    return (min <= value) && (value <= max);
}

bool Interval::surrounds(float value) const {
    return (min < value) && (value < max);
}

float Interval::clamp(float value) const {
    // Clamps value between min and max
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}
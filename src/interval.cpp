#include "interval.h"
#include "constants.h"

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
bool Interval::contains(float value) {
    return (min <= value) && (value <= max);
}

bool Interval::surrounds(float value) {
    return (min < value) && (value < max);
}
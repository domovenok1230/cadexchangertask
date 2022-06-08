#include "helix.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

Point Helix::GetPoint(double angle) {
    return Point(radius * std::cos(angle), radius * std::sin(angle),
                 angle * (step / (2 * M_PI)));
}

Point Helix::GetDerivative(double angle) {
    return Point((-1) * radius * std::sin(angle), radius * std::cos(angle),
                 (step / (2 * M_PI)));
}

void Helix::PrintCurveInfo() {
    std::cout << " Helix with radius = " << radius << " and step = " << step;
}

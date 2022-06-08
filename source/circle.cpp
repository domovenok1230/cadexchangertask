#include "circle.h"
#include <math.h>
#include <iostream>

Point Circle::GetPoint(double angle) {
    return Point(radius * std::cos(angle), radius * std::sin(angle), 0);
}

Point Circle::GetDerivative(double angle) {
    return Point((-1) * radius * std::sin(angle), radius * std::cos(angle), 0);
}

void Circle::PrintCurveInfo() {
    std::cout << " Circcle with radius = " << radius;
}

double Circle::GetRadius() const {
    return radius;
}
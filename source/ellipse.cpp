#include "ellipse.h"
#include <math.h>
#include <iostream>

Point Ellipse::GetPoint(double angle) {
    return Point(r_a * std::cos(angle), r_b * std::sin(angle), 0);
}

Point Ellipse::GetDerivative(double angle) {
    return Point((-1) * r_a * std::sin(angle), r_b * std::cos(angle), 0);
}

void Ellipse::PrintCurveInfo() {
    std::cout << " Ellips with r1 = " << r_a << " and r2 = " << r_b; 
}
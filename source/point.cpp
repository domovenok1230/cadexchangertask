#include "point.h"
#include <cmath>
static const double epsilon = 0.000001f;

std::ostream & operator<<(std::ostream &os, const Point &p) {
    os << " X: " << p.x << " Y: " << p.y << " Z: " << p.z;
    return os;
}

bool Point::operator==(const Point &r_p) const {
    auto var1 = fabs(x - r_p.x);
    auto var2 = fabs(y - r_p.y);
    auto var3 = fabs(z - r_p.z);
    return ((fabs(x - r_p.x) < epsilon) &&
            (fabs(y - r_p.y) < epsilon) &&
            (fabs(z - r_p.z) < epsilon));
}
#pragma once
#include <iostream>

struct Point {
    double x = 0;
    double y = 0;
    double z = 0;
    Point(double x_coord, double y_coord, double z_coord) : x(x_coord), y(y_coord), z(z_coord)
    {}
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    bool operator==(const Point &r_p) const;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#pragma once
#include "base_curves.h"

class Ellipse: public BaseCurve {
    double r_a = 0;
    double r_b = 0;
  public:
    Ellipse(double r1, double r2) : r_a(r1), r_b(r2) {}
    Point GetPoint(double angle) override;
    Point GetDerivative(double angle) override;
    void PrintCurveInfo() override;
    ~Ellipse() = default;
};
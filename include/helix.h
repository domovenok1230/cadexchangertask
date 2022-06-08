#pragma once
#include "base_curves.h"

class Helix : public BaseCurve {
    double radius = 0;
    float step = 0;
  public:
    Helix(double r, double s) : radius(r), step(s) {}
    Point GetPoint(double angle) override;
    Point GetDerivative(double angle) override;
    void PrintCurveInfo() override;
    ~Helix() = default;
};
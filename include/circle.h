#pragma once
#include "base_curves.h"

class Circle : public BaseCurve {
    double radius = 0;
  public:
    Circle(double r) : radius(r) {}
    Point GetPoint(double angle) override;
    Point GetDerivative(double angle) override;
    void PrintCurveInfo() override;
    ~Circle() = default;
    double GetRadius()const;
};
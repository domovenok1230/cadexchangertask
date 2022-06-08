#pragma once
#include "point.h"

class BaseCurve {
  public:
    // calculate point of curve by angle
    virtual Point GetPoint(double angle) = 0;
    // calculate vector first derivative of curve at point by angle
    virtual Point GetDerivative(double angle) = 0;
    // print cummon info about curve
    virtual void PrintCurveInfo() = 0;
    virtual ~BaseCurve() = default;
};
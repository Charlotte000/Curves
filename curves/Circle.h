#pragma once

#include "Curve.h"

class Circle : public Curve
{
public:
    float radius;

    Circle(float radius);

    Vector getPoint(float t) const override;

    Vector getDerivative(float t) const override;
};

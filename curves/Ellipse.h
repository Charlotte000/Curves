#pragma once

#include "Curve.h"

class Ellipse : public Curve
{
public:
    float radiusX, radiusY;

    Ellipse(float radiusX, float radiusY);

    Vector getPoint(float t) const override;

    Vector getDerivative(float t) const override;
};

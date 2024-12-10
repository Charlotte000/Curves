#pragma once

#include "Curve.h"

class Helix : public Curve
{
public:
    float radius, step;

    Helix(float radius, float step);

    Vector getPoint(float t) const override;

    Vector getDerivative(float t) const override;
};

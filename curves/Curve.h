#pragma once

#include "Vector.h"

class Curve
{
public:
    virtual Vector getPoint(float t) const = 0;
    virtual Vector getDerivative(float t) const = 0;
};

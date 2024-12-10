#include "Helix.h"

#include <cmath>
#include <stdexcept>

Helix::Helix(float radius, float step) :
    radius(radius > 0 ? radius : throw std::invalid_argument("Radius must be positive")),
    step(step > 0 ? step : throw std::invalid_argument("Step must be positive"))
{
}

Vector Helix::getPoint(float t) const
{
    return { this->radius * cosf(t), this->radius * sinf(t), this->step * t * (float)M_1_PI / 2 };
}

Vector Helix::getDerivative(float t) const
{
    return { -this->radius * sinf(t), this->radius * cosf(t), this->step * (float)M_1_PI / 2 };
}

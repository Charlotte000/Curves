#include "Circle.h"

#include <cmath>
#include <stdexcept>

Circle::Circle(float radius) :
    radius(radius > 0 ? radius : throw std::invalid_argument("Radius must be positive"))
{
}

Vector Circle::getPoint(float t) const
{
    return { this->radius * cosf(t), this->radius * sinf(t), 0 };
}

Vector Circle::getDerivative(float t) const
{
    return { -this->radius * sinf(t), this->radius * cosf(t), 0 };
}

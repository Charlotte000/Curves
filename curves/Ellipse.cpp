#include "Ellipse.h"

#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(float radiusX, float radiusY) :
    radiusX(radiusX > 0 ? radiusX : throw std::invalid_argument("RadiusX must be positive")),
    radiusY(radiusY > 0 ? radiusY : throw std::invalid_argument("RadiusY must be positive"))
{
}

Vector Ellipse::getPoint(float t) const
{
    return { this->radiusX * cosf(t), this->radiusY * sinf(t), 0 };
}

Vector Ellipse::getDerivative(float t) const
{
    return { -this->radiusX * sinf(t), this->radiusY * cosf(t), 0 };
}

#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(float x, float y, const float width, const float height) {
    const float hw = width / 2.0f;
    const float hh = height / 2.0f;
    this->width = Complex(width, 0);
    this->height = Complex(0, height);
    this->center = Complex(x, y);

    this->topLeft     = Complex(x - hw, y + hh);
    this->topRight    = Complex(x + hw, y + hh);
    this->bottomLeft  = Complex(x - hw, y - hh);
    this->bottomRight = Complex(x + hw, y - hh);
}

void Rectangle::rotate(const float angleStep) {
    const Complex rotator(std::cos(Hyperion::MathUtils::toRadians(angleStep)), std::sin(Hyperion::MathUtils::toRadians(angleStep)));

    topLeft = (topLeft - center) * rotator + center;
    topRight = (topRight - center) * rotator + center;
    bottomLeft = (bottomLeft - center) * rotator + center;
    bottomRight = (bottomRight - center) * rotator + center;
}

void Rectangle::translate(const Complex &C) {
    center = center + C;
    topLeft = topLeft + C;
    topRight = topRight + C;
    bottomLeft = bottomLeft + C;
    bottomRight = bottomRight + C;
}

void Rectangle::scale(const float scalar) {
    topLeft = topLeft * scalar;
    topRight = topRight * scalar;
    bottomLeft = bottomLeft * scalar;
    bottomRight = bottomRight * scalar;
}

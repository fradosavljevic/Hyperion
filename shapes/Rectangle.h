#ifndef HYPERION_RECTANGLE_H
#define HYPERION_RECTANGLE_H
#include "../geometry/Shape2D.h"
#include "../math/Complex.h"

//TODO: check this
class Rectangle : public Shape2D {
public:
    Rectangle(float x, float y, float width, float height);

    void rotate(float angleStep) override;
    void translate(const Complex &C) override;
    void scale(float scalar) override;
private:
    Complex topLeft, topRight, bottomLeft, bottomRight;
    Complex width, height;
};


#endif
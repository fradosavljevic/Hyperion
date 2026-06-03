#ifndef HYPERION_TRIANGLE_H
#define HYPERION_TRIANGLE_H
#include "../geometry/Shape2D.h"


class Triangle : public Shape2D {
public:
    Triangle(const Complex &v1, const Complex &v2, const Complex &v3);
private:
    Complex V1, V2, V3;
};


#endif
#ifndef HYPERION_CUBE_H
#define HYPERION_CUBE_H
#include "../geometry/Shape3D.h"
#include "../math/MathUtils.h"
#include <vector>

class Cube : public Shape3D {
public:
    Cube(int x, int y, int z, int size);
};


#endif
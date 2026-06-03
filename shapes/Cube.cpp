#include "Cube.h"
using namespace Hyperion::MathUtils;

Cube::Cube(const int x, const int y, const int z, const int size) : Shape3D(x, y, z) {
    const float s = static_cast<float>(size) / 2.0f;

    std::vector<Point3D> vertices = {
        {-s, -s, -s}, {s, -s, -s}, {s, s, -s}, {-s, s, -s},
        {-s, -s,  s}, {s, -s,  s}, {s, s,  s}, {-s, s,  s}
    };

    modelVertices = vertices;
    worldVertices = vertices;

    edges = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };
}

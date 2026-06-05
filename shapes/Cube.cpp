#include "Cube.h"
using namespace Hyperion::MathUtils;

Cube::Cube(const float x, const float y, const float z, const float size) : Shape3D(x, y, z) {
    const float s = size / 2.0f;

    std::vector<Vector3> vertices = {
        {-s, -s, -s}, {s, -s, -s}, {s, s, -s}, {-s, s, -s},
        {-s, -s,  s}, {s, -s,  s}, {s, s,  s}, {-s, s,  s}
    };

    modelVertices = vertices;
    worldVertices.resize(vertices.size());

    edges = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    faces = {
        {0,2,1},
        {0,3,2},

        {4,5,6},
        {4,6,7},

        {0,1,5},
        {0,5,4},

        {1,2,6},
        {1,6,5},

        {2,3,7},
        {2,7,6},

        {3,0,4},
        {3,4,7}
    };
}

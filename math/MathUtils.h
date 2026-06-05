#ifndef HYPERION_MATHUTILS_H
#define HYPERION_MATHUTILS_H
#include "Constants.h"

//FIXME: Separate utils from data structures
namespace Hyperion::MathUtils {
    template<typename T>
    T lerp(const T& start, const T& end, float t) {
        return start + (end - start) * t;
    }

    inline float clamp(const float val, const float min, const float max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }

    inline float toRadians(const float degrees) {
        return degrees * (Constants::H_PI / 180.0f);
    }

    struct Point2D {
        float x{}, y{};
        bool visible = false;
    };

    struct Point3D {
        float x, y, z;
    };

    struct Edge {
        int start, end;
    };

    struct Face {
        int a;
        int b;
        int c;
    };
}

#endif

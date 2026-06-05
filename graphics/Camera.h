#ifndef HYPERION_CAMERA_H
#define HYPERION_CAMERA_H
#include "../math/Vector3.h"

class Camera {
public:
    explicit Camera(const Vector3& position = Vector3(0,0,-5), const float fov = 90.0f)
        : position(position),
          fov(fov) {}

    [[nodiscard]] const Vector3& getPosition() const { return position; }
    [[nodiscard]] float getFov() const { return fov; }

private:
    Vector3 position;
    float fov;
};


#endif
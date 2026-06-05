#include "Shape3D.h"
#include <cmath>

using namespace Hyperion::MathUtils;

void Shape3D::translate(const Vector3 &V) {
    this->position = this->position + V;
}

//TODO: finish this
void Shape3D::scale(float scalar) {}

//TODO: check this
void Shape3D::rotate(const float angleX, const float angleY, const float angleZ) {
    const float halfX = toRadians(angleX) * 0.5f;
    const float halfY = toRadians(angleY) * 0.5f;
    const float halfZ = toRadians(angleZ) * 0.5f;

    const Quaternion qX(std::cos(halfX), std::sin(halfX), 0, 0);
    const Quaternion qY(std::cos(halfY), 0, std::sin(halfY), 0);
    const Quaternion qZ(std::cos(halfZ), 0, 0, std::sin(halfZ));

    orientation = (qZ * (qY * (qX * orientation))).unit();
}

void Shape3D::update() {
    const Quaternion invOrientation = orientation.conjugate();

    for (size_t i = 0; i < modelVertices.size(); i++) {
        Quaternion P(0, modelVertices[i].getX(), modelVertices[i].getY(), modelVertices[i].getZ());
        Quaternion rotated = orientation * P * invOrientation;

        worldVertices[i] = Vector3(
            rotated.getX() + this->position.getX(),
            rotated.getY() + this->position.getY(),
            rotated.getZ() + this->position.getZ()
        );
    }
}

Vector3 Shape3D::getPosition() const {
    return this->position;
}

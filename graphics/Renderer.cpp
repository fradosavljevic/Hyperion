#include "Renderer.h"
#include <cmath>
#include <iostream>

Renderer::Renderer(ScreenBuffer *screenBuffer) : targetBuffer(screenBuffer), camera(new Camera()) {}

void Renderer::draw2DShape(const Shape2D &shape) const {
    for (const auto& [start, end] : shape.getEdges()) {
        auto& v1 = shape.getWorldVertices()[start];
        auto& v2 = shape.getWorldVertices()[end];

        targetBuffer->drawLine(static_cast<float>(v1.x), static_cast<float>(v1.y), static_cast<float>(v2.x), static_cast<float>(v2.y));
    }
}

void Renderer::draw3DShape(Shape3D &shape) const {
    shape.update();

    const auto& worldVertices = shape.getWorldVertices();
    const auto& shapeFaces = shape.getFaces();
    const auto& shapeEdges = shape.getEdges();

    for (const auto& [a, b, c] : shapeFaces) {
        Vector3 A = worldVertices[a];
        Vector3 B = worldVertices[b];
        Vector3 C = worldVertices[c];

        Vector3 AB = B - A;
        Vector3 AC = C - A;
        Vector3 view = camera->getPosition() - A;
        Vector3 normal = AB.cross(AC);

        if (normal.dot(view) < 0.0f)
            continue;

        drawProjectedLine(A, B);
        drawProjectedLine(B, C);
        drawProjectedLine(C, A);
    }
}

void Renderer::drawProjectedLine(const Vector3& a, const Vector3& b) const {
    auto p1 = this->project(a);
    auto p2 = this->project(b);

    if (p1.visible && p2.visible)
    {
        targetBuffer->drawLine(
            p1.x, p1.y,
            p2.x, p2.y
        );
    }
}

Hyperion::MathUtils::Point2D Renderer::project(const Vector3 &point) const {
    Hyperion::MathUtils::Point2D projection;

    Vector3 cameraSpace = point - camera->getPosition();
    const float z_dist = cameraSpace.getZ();

    if (z_dist <= 0.1f) {
        projection.visible = false;
        return projection;
    }

    const float factor =
        (static_cast<float>(targetBuffer->getWidth()) / 2.0f) /
        std::tan(Hyperion::MathUtils::toRadians(camera->getFov() * 0.5f));

    const float projectedX =
        (cameraSpace.getX() / z_dist) * factor;

    float projectedY =
        (cameraSpace.getY() / z_dist) * factor;

    projectedY *= 0.5f;

    projection.x = projectedX + (float)targetBuffer->getWidth() * 0.5f;
    projection.y = projectedY + (float)targetBuffer->getHeight() * 0.5f;

    projection.visible = true;

    return projection;
}

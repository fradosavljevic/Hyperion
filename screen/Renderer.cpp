#include "Renderer.h"
#include <cmath>
#include <iostream>

Renderer::Renderer(ScreenBuffer *screenBuffer) : targetBuffer(screenBuffer) {}

void Renderer::draw2DShape(const Shape2D &shape) const {
    for (const auto& [start, end] : shape.getEdges()) {
        auto& v1 = shape.getWorldVertices()[start];
        auto& v2 = shape.getWorldVertices()[end];

        targetBuffer->drawLine(static_cast<float>(v1.x), static_cast<float>(v1.y), static_cast<float>(v2.x), static_cast<float>(v2.y));
    }
}

void Renderer::draw3DShape(Shape3D &shape) const {
    //shape.update(); //problem

    for (const auto& [start, end] : shape.getEdges()) {
        auto& v1 = shape.getWorldVertices()[start];
        auto& v2 = shape.getWorldVertices()[end];

        auto p1 = targetBuffer->project(v1.x, v1.y, v1.z);
        auto p2 = targetBuffer->project(v2.x, v2.y, v2.z);

        if (p1.visible && p2.visible) {
            targetBuffer->drawLine(p1.x, p1.y, p2.x, p2.y);
        }
    }
}

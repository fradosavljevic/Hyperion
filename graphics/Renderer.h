#ifndef HYPERION_RENDERER_H
#define HYPERION_RENDERER_H
#include "Camera.h"
#include "ScreenBuffer.h"
#include "../geometry/Shape3D.h"
#include "../geometry/Shape2D.h"

class Renderer {
public:
    explicit Renderer(ScreenBuffer* screenBuffer);
    void draw2DShape(const Shape2D& shape) const;
    void draw3DShape(Shape3D& shape) const;
    void drawProjectedLine(const Vector3& a, const Vector3& b) const;
    [[nodiscard]] Hyperion::MathUtils::Point2D project(const Vector3& point) const;
private:
    ScreenBuffer* targetBuffer;
    Camera* camera;
};


#endif
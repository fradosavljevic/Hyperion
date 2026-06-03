#ifndef HYPERION_RENDERER_H
#define HYPERION_RENDERER_H
#include "ScreenBuffer.h"
#include "../geometry/Shape3D.h"
#include "../geometry/Shape2D.h"

class Renderer {
public:
    explicit Renderer(ScreenBuffer* screenBuffer);
    void draw2DShape(const Shape2D& shape) const;
    void draw3DShape(Shape3D& shape) const;
private:
    ScreenBuffer* targetBuffer;
};


#endif
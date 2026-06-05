#ifndef HYPERION_SHAPE2D_H
#define HYPERION_SHAPE2D_H
#include "Shape.h"
#include "../math/Complex.h"
#include "../graphics/ScreenBuffer.h"


class Shape2D : public Shape {
public:
    Shape2D() = default;
    ~Shape2D() override = default;

    virtual void rotate(float angle) = 0;
    virtual void translate(const Complex& C) = 0;
    virtual void scale(float scalar) = 0;

    [[nodiscard]] const std::vector<Hyperion::MathUtils::Edge>& getEdges() const { return edges; };
    [[nodiscard]] const std::vector<Hyperion::MathUtils::Point2D>& getWorldVertices() const { return worldVertices; }
protected:
    Complex center;
    float angle{};
    std::vector<Hyperion::MathUtils::Edge> edges;
    std::vector<Hyperion::MathUtils::Point2D> worldVertices;
};


#endif
#ifndef HYPERION_SHAPE3D_H
#define HYPERION_SHAPE3D_H
#include "Shape.h"
#include "../math/MathUtils.h"
#include "../math/Quaternion.h"
#include "../math/Vector3.h"
#include <vector>

class Shape3D : public Shape {
public:
    explicit Shape3D(const float x = 0, const float y = 0, const float z = 0) : x(x), y(y), z(z), orientation(Quaternion(1, 0, 0, 0)) {};

    virtual void translate(const Vector3& V);
    virtual void scale(float scalar);
    virtual void rotate(float angleX, float angleY, float angleZ);
    void update() override;

    [[nodiscard]] const std::vector<Hyperion::MathUtils::Edge>& getEdges() const { return edges; };
    [[nodiscard]] const std::vector<Hyperion::MathUtils::Point3D>& getWorldVertices() const { return worldVertices; }
protected:
    float x, y, z;
    Quaternion orientation;
    std::vector<Hyperion::MathUtils::Edge> edges;
    std::vector<Hyperion::MathUtils::Point3D> modelVertices;
    std::vector<Hyperion::MathUtils::Point3D> worldVertices;
};


#endif
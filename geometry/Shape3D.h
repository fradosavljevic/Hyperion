#ifndef HYPERION_SHAPE3D_H
#define HYPERION_SHAPE3D_H
#include "Shape.h"
#include "../math/MathUtils.h"
#include "../math/Quaternion.h"
#include "../math/Vector3.h"
#include <vector>

class Shape3D : public Shape {
public:
    explicit Shape3D(const float x = 0, const float y = 0, const float z = 0) : position(x, y, z), orientation(Quaternion(1, 0, 0, 0)) {};

    virtual void translate(const Vector3& V);
    virtual void scale(float scalar);
    virtual void rotate(float angleX, float angleY, float angleZ);
    void update() override;

    [[nodiscard]] Vector3 getPosition() const;
    [[nodiscard]] const std::vector<Hyperion::MathUtils::Face>& getFaces() const { return faces; }
    [[nodiscard]] const std::vector<Hyperion::MathUtils::Edge>& getEdges() const { return edges; };
    [[nodiscard]] const std::vector<Vector3>& getWorldVertices() const { return worldVertices; }
protected:
    Vector3 position;
    Quaternion orientation;
    std::vector<Hyperion::MathUtils::Face> faces;
    std::vector<Hyperion::MathUtils::Edge> edges;
    std::vector<Vector3> modelVertices;
    std::vector<Vector3> worldVertices;
};


#endif
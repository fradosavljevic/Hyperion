#ifndef HYPERION_VECTOR3_H
#define HYPERION_VECTOR3_H
#include <iosfwd>


class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);
    ~Vector3() = default;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float getX() const;
    [[nodiscard]] float getY() const;
    [[nodiscard]] float getZ() const;
    [[nodiscard]] Vector3 unit() const;
    [[nodiscard]] float dot(const Vector3 &v) const;
    [[nodiscard]] Vector3 cross(const Vector3 &v) const;

    Vector3& operator=(const Vector3& v);
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(float scalar) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
private:
    float x, y, z;
};


#endif
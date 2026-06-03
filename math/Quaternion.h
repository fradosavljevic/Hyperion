#ifndef HYPERION_QUATERNION_H
#define HYPERION_QUATERNION_H
#include <iosfwd>


class Quaternion {
public:
    Quaternion();
    Quaternion(float r, float x, float y, float z);
    ~Quaternion() = default;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float getReal() const { return r; };
    [[nodiscard]] float getX() const { return x; };
    [[nodiscard]] float getY() const { return y; };
    [[nodiscard]] float getZ() const { return z; };
    [[nodiscard]] Quaternion conjugate() const;
    [[nodiscard]] Quaternion unit() const;

    Quaternion& operator=(const Quaternion& q);
    Quaternion operator+(const Quaternion& q) const;
    Quaternion operator-(const Quaternion& q) const;
    Quaternion operator*(const Quaternion& q) const;
    Quaternion operator*(float scalar) const;
    friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);
private:
    float r, x, y, z;
};


#endif
#include "Quaternion.h"
#include <cmath>
#include <ostream>

Quaternion::Quaternion() {
    this->r = this->x = this->y = this->z = 0.0f;
}

Quaternion::Quaternion(const float r, const float x, const float y, const float z) {
    this->r = r; this->x = x; this->y = y; this->z = z;
}

float Quaternion::magnitude() const {
    return std::sqrt(this->r * this->r + this->x * this->x + this->y * this->y + this->z * this->z);
}

Quaternion Quaternion::conjugate() const {
    return {this->r, -this->x, -this->y, -this->z};
}

Quaternion Quaternion::unit() const {
    float magnitude = this->magnitude();
    if (magnitude < 1e-7f) return {1, 0, 0, 0};
    return {this->r / magnitude, this->x / magnitude, this->y / magnitude, this->z / magnitude};
}

Quaternion& Quaternion::operator=(const Quaternion& q) {
    if (this != &q) {
         this->r = q.r; this->x = q.x; this->y = q.y; this->z = q.z;
    }
    return *this;
}

Quaternion Quaternion::operator+(const Quaternion &q) const {
    return {this->r + q.r, this->x + q.x, this->y + q.y, this->z + q.z};
}

Quaternion Quaternion::operator-(const Quaternion &q) const {
    return {this->r - q.r, this->x - q.x, this->y - q.y, this->z - q.z};
}

Quaternion Quaternion::operator*(const Quaternion &q) const {
    float a1 = this->r, b1 = this->x, c1 = this->y, d1 = this->z;
    float a2 = q.r, b2 = q.x, c2 = q.y, d2 = q.z;
    return {a1*a2 - b1*b2 - c1*c2 - d1*d2,
               a1*b2 + b1*a2 + c1*d2 - d1*c2,
               a1*c2 - b1*d2 + c1*a2 + d1*b2,
               a1*d2 + b1*c2 - c1*b2 + d1*a2};
}

Quaternion Quaternion::operator*(const float scalar) const {
    return {this->r * scalar, this->x * scalar, this->y * scalar, this->z * scalar};
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
    os << q.r << " + i" << q.x << " + j" << q.y  << " + k" << q.z << std::endl;
    return os;
}
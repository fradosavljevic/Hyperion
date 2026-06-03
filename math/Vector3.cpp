#include "Vector3.h"
#include <cmath>
#include <ostream>

Vector3::Vector3() {
    this->x = this->y = this->z = 0.0f;
}

Vector3::Vector3(const float x, const float y, const float z) {
    this->x = x; this->y = y; this->z = z;
}

float Vector3::magnitude() const {
    return std::sqrt(x*x + y*y + z*z);
}

float Vector3::getX() const {
    return this->x;
}

float Vector3::getY() const {
    return this->y;
}

float Vector3::getZ() const {
    return this->z;
}

Vector3 Vector3::unit() const {
    float magnitude = this->magnitude();
    if (magnitude < 1e-7f) return {0, 0, 0};
    return {this->x / magnitude, this->y / magnitude, this->z / magnitude};
}

float Vector3::dot(const Vector3 &v) const {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x
    };
}

Vector3 &Vector3::operator=(const Vector3 &v) {
    if (this != &v) {
        this->x = v.x; this->y = v.y; this->z = v.z;
    }
    return *this;
}

Vector3 Vector3::operator+(const Vector3 &v) const {
    return {this->x + v.x, this->y + v.y, this->z + v.z};
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {this->x - v.x, this->y - v.y, this->z - v.z};
}

Vector3 Vector3::operator*(const float scalar) const {
    return {this->x * scalar, this->y * scalar, this->z * scalar};
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
    return os;
}
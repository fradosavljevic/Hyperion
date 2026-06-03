#include "ScreenBuffer.h"

#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
using namespace Hyperion::MathUtils;

ScreenBuffer::ScreenBuffer() {
    this->width = 80;
    this->height = 40;
    resizeBuffer();
}

ScreenBuffer::ScreenBuffer(const int width, const int height) {
    this->width = width;
    this->height = height;
    resizeBuffer();
}

void ScreenBuffer::resizeBuffer() {
    this->screenBuffer.resize(this->height, std::string(this->width, ' '));
}

//FIXME: Rewrite this
void ScreenBuffer::drawPixel(const int x, const int y, const char pixel) {
    int xr, yr;
    wrap(x, y, &xr, &yr);
    this->screenBuffer[yr][xr] = pixel;
}

void ScreenBuffer::wrap(int x, int y, int* xr, int* yr) const {
    *xr = (x % this->width + this->width) % this->width;
    *yr = (y % this->height + this->height) % this->height;
}

//FIXME: float -> int
void ScreenBuffer::drawLine(float x1, float y1, float x2, float y2) {
    int x = static_cast<int>(std::round(x1));
    int y = static_cast<int>(std::round(y1));
    int targetX = static_cast<int>(std::round(x2));
    int targetY = static_cast<int>(std::round(y2));

    int dx = std::abs(targetX - x);
    int dy = -std::abs(targetY - y);
    int sx = (x < targetX) ? 1 : -1;
    int sy = (y < targetY) ? 1 : -1;
    int err = dx + dy;

    while (true) {
        this->drawPixel(x, y, '#');

        if (x == targetX && y == targetY) break;

        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y += sy;
        }
    }
}

int ScreenBuffer::getWidth() const {
    return width;
}

int ScreenBuffer::getHeight() const {
    return height;
}

Point2D ScreenBuffer::project(const float x, const float y, const float z) const {
    Point2D projection;

    const float z_dist = z + 5.0f;

    if (z_dist <= 0.1f) {
        projection.visible = false;
        return projection;
    }
    constexpr float fov = 90.0f;
    const float factor = (static_cast<float>(this->width) / 2.0f) / tan(toRadians(fov * 0.5f));

    const float projectedX = (x / z_dist) * factor;
    float projectedY = (y / z_dist) * factor;

    projectedY *= 0.5f;

    projection.x = static_cast<int>(projectedX + static_cast<float>(width) / 2);
    projection.y = static_cast<int>(projectedY + static_cast<float>(height) / 2);
    projection.visible = true;

    return projection;
}

void ScreenBuffer::printScreen() const {
    std::string frame = "\033[H";
    for (const auto& line : this->screenBuffer) {
        frame += line + "\n";
    }
    std::cout << frame << std::flush;
}

void ScreenBuffer::clearScreen() {
    for (int i = 0; i < this->height; ++i) {
        std::fill(this->screenBuffer[i].begin(), this->screenBuffer[i].end(), ' ');
    }
}

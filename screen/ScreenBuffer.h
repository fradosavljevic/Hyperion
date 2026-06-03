#ifndef HYPERION_SCREENBUFFER_H
#define HYPERION_SCREENBUFFER_H
#include <string>
#include <vector>
#include "../math/MathUtils.h"

class ScreenBuffer {
public:
    ScreenBuffer();
    ScreenBuffer(int width, int height);
    ~ScreenBuffer() = default;

    void drawLine(float x1, float y1, float x2, float y2);
    void drawPixel(int x, int y, char pixel);
    void wrap(int x, int y, int* xr, int* yr) const;
    int getWidth() const;
    int getHeight() const;

    [[nodiscard]] Hyperion::MathUtils::Point2D project(float x, float y, float z) const;

    void printScreen() const;
    void clearScreen();

private:
    int width, height;
    void resizeBuffer();
    std::vector<std::string> screenBuffer;
};


#endif
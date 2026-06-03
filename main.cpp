#include <chrono>
#include <thread>
#include "screen/Renderer.h"
#include "screen/ScreenBuffer.h"
#include "shapes/Cube.h"

constexpr int WIDTH = 80;
constexpr int HEIGHT = 40;

//TODO: Refactor all coordinate calculations to use float; apply int casting only at the screen buffer level.

[[noreturn]] int main() {
    auto* newBuffer = new ScreenBuffer(WIDTH, HEIGHT);

    auto myCube = Cube(8, 0, 0, 3);
    auto* renderer = new Renderer(newBuffer);

    auto lastTime = std::chrono::high_resolution_clock::now();
    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        newBuffer->clearScreen();
        // FIXME: Translate is not working correctly for 3D shapes; fix projection-related issues.
        //myCube.translate({0.0f, 0, 0});
        renderer->draw3DShape(myCube);

        myCube.rotate(45.0f * dt, -35.0f * dt, -20.0f * dt);

        newBuffer->printScreen();
    }
}
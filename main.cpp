#include <chrono>
#include <thread>
#include "graphics/Renderer.h"
#include "graphics/ScreenBuffer.h"
#include "shapes/Cube.h"

constexpr int WIDTH = 80;
constexpr int HEIGHT = 40;

//TODO: Refactor all coordinate calculations to use float; apply int casting only at the screen buffer level.

[[noreturn]] int main() {
    auto* newBuffer = new ScreenBuffer(WIDTH, HEIGHT);

    auto myCube = Cube(0, 0, 0, 4);
    auto* renderer = new Renderer(newBuffer);

    auto lastTime = std::chrono::high_resolution_clock::now();
    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        newBuffer->clearScreen();

        //myCube.translate({1.0f * dt, 0.0f * dt, 0.0f * dt});
        myCube.rotate(15.0f * dt, 20.0f * dt, 10.0f * dt);
        renderer->draw3DShape(myCube);

        newBuffer->printScreen();
    }
}
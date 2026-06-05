cmake_minimum_required(VERSION 4.1)
project(Hyperion)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComplexNumbers main.cpp
        Math/Complex.cpp
        Math/Complex.h
        Math/Constants.h
        graphics/ScreenBuffer.cpp
        graphics/ScreenBuffer.h
        Geometry/Shape2D.cpp
        Geometry/Shape2D.h
        Shapes/Rectangle.cpp
        Shapes/Rectangle.h
        Math/MathUtils.h
        Shapes/Triangle.cpp
        Shapes/Triangle.h
        Math/Quaternion.cpp
        Math/Quaternion.h
        Math/Vector3.cpp
        Math/Vector3.h
        Geometry/Shape3D.cpp
        Geometry/Shape3D.h
        Geometry/Shape.h
        Shapes/Cube.cpp
        Shapes/Cube.h
        graphics/Renderer.cpp
        graphics/Renderer.h
        graphics/Camera.cpp
        graphics/Camera.h
)

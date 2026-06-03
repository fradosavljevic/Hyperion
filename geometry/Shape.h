#ifndef HYPERION_SHAPE_H
#define HYPERION_SHAPE_H

class Shape {
public:
    Shape() = default;
    virtual ~Shape() = default;
    virtual void update() = 0;
};


#endif
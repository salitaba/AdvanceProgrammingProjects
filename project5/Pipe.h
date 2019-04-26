#ifndef PIPE_H
#define PIPE_H

#include"RSDL/src/rsdl.hpp"
#include"ObjectCode.h"

class Pipe{
public:
    Pipe(Point _position, int _type);
    void show(Window &window, Point cameraPosition);
    Rectangle getRectangle();
private:
    Point position;
    int type;
};


#endif
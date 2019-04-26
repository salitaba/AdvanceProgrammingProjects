#ifndef FLAG_H
#define FLAG_H

#include"RSDL/src/rsdl.hpp"
#include"ObjectCode.h"
#include<string>

class Flag{
public:
    Flag();
    Flag(Point _position, int _type);
    void show(Window &window,Point cameraPosition);
    Rectangle getRectangle();
private:
    Point position;
    int type;
};

#endif
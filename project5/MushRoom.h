#ifndef MUSHROOM_H
#define MUSHROOM_H  

#include"RSDL/src/rsdl.hpp"
#include"Move.h"

class MushRoom{
public: 
    MushRoom(Point point, bool _online);
    void show(Window &window, Point _cameraPosition);
    void fixCrashing(Point topLeft,Point downRight);
    void updatePosition(int refreshRate, Point cameraPosition);
    Rectangle getRectangle();
    void offline();
private:
    Point position;
    bool online;
    int counter; 
    Move movement;
    bool die = false;
};

#endif
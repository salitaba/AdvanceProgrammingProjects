#ifndef KOPA_H
#define KOPA_H

#include"RSDL/src/rsdl.hpp"
#include"Move.h"
#include"PictureChanger.h"

class Kopa{
public:
    Kopa(Point _position);
    void show(Window &window, Point cameraPosition);
    void goLeft();
    void goRight();
    void updatePosition(int refreshrate, Point cameraPosition, Window &window);
    void fixCrashingWithBlock(Point topLeft,Point downRight);
    Rectangle getRectangle();
private:
    int height, width;
    Point position;
    Move movement;
    PictureChanger sourceImage;
};



#endif 
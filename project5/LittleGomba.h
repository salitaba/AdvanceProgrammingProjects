#ifndef LITTLEGOMBA_H
#define LITTLEGOMBA_H

#include"RSDL/src/rsdl.hpp"
#include"Accident.h"
#include"Move.h"
#include"PictureChanger.h"


class LittleGomba{
public:
    LittleGomba(Point _position);
    void show(Window &window, Point cameraPosition);
    void goLeft();
    void goRight();
    void updatePosition(int refreshrate, Point cameraPosition, Window &window);
    Rectangle getRectangle();
    void fixCrashingWithBlock(Point topLeft,Point downRight);
    void die();
    bool isOnline();
private:
    int counter = 30;
    bool lived = true;
    Point position ;
    Move movement;
    int stoped = true;
    PictureChanger sourceImage;
};

#endif
#ifndef MARIO_H
#define MARIO_H

#include<string>
#include"RSDL/src/rsdl.hpp"
#include"Move.h"
#include"Crash.h"
#include"ObjectCode.h"


class Mario{
public:
    Mario();
    Mario(Point position);
    Point getPosition();
    void show(Window &window, Point cameraPosition);
    void goRight();
    void goLeft();
    void stop();
    void updatePosition(int refreshRate);
    bool isGoLeft();
    bool isGoRight();
    void dontJump();
    bool jump();
    int fixCrashingWithBlock(Point topLeft, Point downRight);
    void canJump();
    void cantJump();
    bool stoped();
    void die();
    Rectangle getRectangle();
private:
    bool lived = true;
    Point position;
    Move movement;
    int width, height;
    std::string marioSourceImage;
    int lastTimeImageUpdate;
    
};

#endif
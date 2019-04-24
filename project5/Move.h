#ifndef MOVE_H
#define MOVE_H

#include"RSDL/src/rsdl.hpp"

class Move{
public:
    Point goRight(Point position);
    void goRight();
    void goLeft();
    void stop();
    Point updatePosition(int refreshRate, Point position);
    bool isGoLeft();
    bool isGoRight();
    void dontJump();
    void jump();
    int getVX();
    int getAX();
    bool isBeforTowardRight();
    void downAccident();
private:
    bool beforTowardRight = true;
    double vx = 0, vy = 0;
    double g = 1000, ax = 0, ay = 0, fx = 1000;
    bool jumped = false, onGround = true;
};



#endif
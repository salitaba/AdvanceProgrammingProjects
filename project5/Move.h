#ifndef MOVE_H
#define MOVE_H

#include"RSDL/src/rsdl.hpp"
#include"Accident.h"


class Move{
public:
    Move(Point position, int _speedLimit);
    Point goRight(Point position);
    void goRight();
    void goLeft();
    void stop();
    Point updatePosition(int refreshRate, Point position);
    bool isGoLeft();
    bool isGoRight();
    void dontJump();
    bool jump();
    int getVX();
    int getAX();
    bool isBeforTowardRight();
    void downAccident();
    void leftAccident();
    void dontAccident();
    Point returnPreviuseLocation();
    void upAccident();
    void noAccident();
    bool getOnGround();
    bool stoped();
    void canJump();
    void die();
    double vx = 0, vy = 0;
private:
    bool onGround = true;
    bool lived = true;
    Point previuseLocation;
    bool beforTowardRight = true;
    double g = 1000, ax = 0, ay = 0, fx = 300;
    bool jumped = false;
    int speedLimit = 200;
};



#endif
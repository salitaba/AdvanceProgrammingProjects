#ifndef CRASH_H
#define CRASH_H

#include"RSDL/src/rsdl.hpp"
#include"Line.h"

class Crash{
public:
    Crash(Point _previuseTopLeft, Point _topLeft1,Point _topLeft2,Point _downRight1,Point _downRight2);
    Point leftAccident();
    Point righAccident();
    Point upAccident();
    Point downAccident();
private:
    Point topLeft1, topLeft2, downRight1, downRight2;
    Point previuseTopLeft;
};


#endif
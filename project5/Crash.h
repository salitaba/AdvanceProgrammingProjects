#ifndef CRASH_H
#define CRASH_H

#include"RSDL/src/rsdl.hpp"

class Crash{
public:
    Crash(Point _topLeft1,Point _topLeft2,Point _downRight1,Point _downRight2);
    bool leftAccident();
    bool righAccident();
    bool upAccident();
    Point downAccident();
private:
    Point topLeft1, topLeft2, downRight1, downRight2;
};


#endif
#ifndef LINE_H
#define LINE_H

#include"RSDL/src/rsdl.hpp"

class Line{
public:
    Line(Point A,Point B);
    int getXWithY(int y);
    int getYWithX(int x);
private:
    Point a,b;
};

#endif
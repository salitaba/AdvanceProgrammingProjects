#ifndef ACCIDENT_H
#define ACCIDENT_H

#include"RSDL/src/rsdl.hpp"

class Accident{
public:
    bool check(Rectangle a,Rectangle b);
    bool pointAccident(Point a, Rectangle b);
};

#endif
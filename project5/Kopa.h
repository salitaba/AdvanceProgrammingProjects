#ifndef KOPA_H
#define KOPA_H

#include"RSDL/src/rsdl.hpp"

class Kopa{
public:
    Kopa(Point _position);
    void show(Window &window, Point cameraPosition);
private:
    Point position;
};



#endif 
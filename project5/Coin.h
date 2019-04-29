#ifndef COIN_H
#define COIN_H

#include"RSDL/src/rsdl.hpp"

class Coin{
public:
    Coin(Point point,bool online);
    void show(Window &window, Point cameraPosition);
private:
    Point position;
    int counter;
};


#endif
#ifndef BLOCK_H
#define BLOCK_H

#include<string>
#include"RSDL/src/rsdl.hpp"
#include"ObjectCode.h"

class Block{
public:
    Block(Point _cell, int _type);
    void show(Window &window, Point cameraPosition);
    Point getCell();
    int getHeight();
    int getWidth();
private:
    int type;
    Point cell;
    int width, height;
    std::string sourceImage;
};


#endif
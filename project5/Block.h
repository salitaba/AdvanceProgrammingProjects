#ifndef BLOCK_H
#define BLOCK_H

#include<string>
#include"RSDL/src/rsdl.hpp"
#include"ObjectCode.h"
#include"PictureChanger.h"
#include"Coin.h"
#include"MushRoom.h"

class Block{
public:
    Block(Point _cell, int _type);
    void show(Window &window, Point cameraPosition);
    Point getCell();
    int getHeight();
    int getWidth();
    bool accident();
    void mushroomFixCrashing(Point topLeft, Point downRight);
    void mushroomUpdatePosition(int refreshRate, Point cameraPosition);
    Rectangle getMushroomRectangle();
    void mushroomOffline();
private:
    int type;
    Point cell;
    int width, height;
    std::string sourceImage;
    PictureChanger questionSourceImage;
    Coin coin;
    MushRoom mushroom;
    bool online = true;
};


#endif
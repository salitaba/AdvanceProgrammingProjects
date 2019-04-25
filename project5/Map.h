#ifndef MAP_H
#define MAP_H

#include<string>
#include<vector>
#include<iostream>
#include<fstream>

#include"Object.h"
#include"RSDL/src/rsdl.hpp"
#include"RSDL/src/rsdl.hpp"
#include"ObjectCode.h"

class Object;

class Map{
public:
    Map(std::string sourceAddress); 
    int getWidth();
    int getHeight();
    char getCharXY(int x,int y);
    Object createObjects();
    Window getWindowFitMap();
private:
    std::vector<std::string> map;
};

#endif
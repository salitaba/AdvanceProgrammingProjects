#ifndef BACKGROUND_H
#define BACKGROUND_H

#include<string>
#include<iostream>

#include"RSDL/src/rsdl.hpp"


class Background{
public:
    Background();
    void show(Window &window, Point cameraPosition);
    
private:
};

#endif
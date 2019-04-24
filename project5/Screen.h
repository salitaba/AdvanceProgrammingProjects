#ifndef SCREEN_H
#define SCREEN_H

#include"Map.h"
#include"Cell.h"
#include"Object.h"
#include"RSDL/src/rsdl.hpp"

class Screen{
public:
    Screen(Window &_window);
    void updateScreen(Object objects);
    void showBackGround();
private:
    Window window;
    int refreshScreenRate;
    int cameraPositionX;
    
};

#endif
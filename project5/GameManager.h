#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"Map.h"
#include"Screen.h"
#include"Mario.h"
#include"Object.h"
#include"RSDL/src/rsdl.hpp"

class GameManager{
public:
    GameManager(Map map, Window &_window, int _screenRefreshRate);
    void start();
    void handleEvent();
private:
    Window window;
    int screenRefreshRate;
    Screen screen;
    Object objects;
    int lastTimeScreenUpdate;
};

#endif
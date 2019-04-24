#ifndef OBJECT_H
#define OBJECT_H

#include<vector>

#include"Mario.h"
#include"Background.h"
#include"Block.h"
#include"Kopa.h"
#include"Pipe.h"
#include"Flag.h"
#include"Map.h"
#include"Block.h"

class Object{
public:
    Object();
    void updateScreen(Window &window);
    void updatePosition(int refreshRate, Window &window);
    bool isMarioOnFlag();
    void setMario(Point cell);
    void addBlock(Point cell, int type);
    void goMarioRight();
    void goMarioLeft();
    void stopMario();
    bool isMarioGoLeft();
    bool isMarioGoRight();
    void jumpMario();
    void dontJumpMario();
    void fixCrashing();
private:
    Background background;
    Mario mario;
    std::vector<Block> blocks;
    std::vector<Kopa> kopas;
    std::vector<Pipe> pipes;
    Flag flag;
    Point cameraPosition;
};


#endif
#include"Move.h"

using namespace std;

Point Move::updatePosition(int refreshRate,Point position){
    if(vx < 0)
        beforTowardRight = false;
    else if(vx > 0)
        beforTowardRight = true;
    vx = vx + refreshRate * ax / 1000.0;
    if(vx > 0){
        vx = min(vx, 200.0);
        vx = vx - fx * refreshRate / 1000.0;
        if(ax == 0)
            vx = max(vx, 0.0);
    }else if(vx < 0){
        vx = max(vx, -200.0);
        vx = vx + fx * refreshRate / 1000.0;
        if(ax == 0)
            vx = min(vx, 0.0);

    }
    position.x += (int)(refreshRate * vx / 1000.0);

    vy = vy + refreshRate * g / 1000.0;
    position.y += (int)(refreshRate * vy / 1000.0);
    return position;
}

void Move::goRight(){ ax = 1400 ; }

void Move::goLeft(){ ax = -1400 ; }

void Move::stop(){ ax = 0; }

bool Move::isGoLeft(){ return ax < 0; }

bool Move::isGoRight(){ return ax > 0; }

void Move::dontJump(){ jumped = false; }

void Move::jump(){ 
    vy = -500;
    jumped = true;
}

int Move::getVX(){ return vx; }

int Move::getAX(){ return ax; }

bool Move::isBeforTowardRight(){return beforTowardRight; }

void Move::downAccident(){
    vy = 0;
    onGround = true;
}
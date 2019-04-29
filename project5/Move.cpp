#include"Move.h"

using namespace std;

Move::Move(Point position, int _speedLimit):previuseLocation(position), speedLimit(_speedLimit){}

Point Move::updatePosition(int refreshRate,Point position){
    // cout<<onGround<<endl;
    // onGround = false;
    previuseLocation = position;
    if(vx < 0)
        beforTowardRight = false;
    else if(vx > 0)
        beforTowardRight = true;
    vx = vx + refreshRate * ax / 1000.0;
    if(vx > 0){
        vx = min(vx, (double)speedLimit);
        vx = vx - fx * refreshRate / 1000.0;
        if(ax == 0)
            vx = max(vx, 0.0);
    }else if(vx < 0){
        vx = max(vx, -(double)speedLimit);
        vx = vx + fx * refreshRate / 1000.0;
        if(ax == 0)
            vx = min(vx, 0.0);

    }
    if(lived == true)
        position.x += (int)(refreshRate * vx / 1000.0);

    vy = vy + refreshRate * g / 1000.0;
    position.y += (int)(refreshRate * vy / 1000.0);
    return position;
}

void Move::goRight(){ ax = 900 ; }

void Move::goLeft(){ ax = -900 ; }

void Move::stop(){ ax = 0; }

bool Move::isGoLeft(){ return ax < 0; }

bool Move::isGoRight(){ return ax > 0; }

void Move::dontJump(){ jumped = false; }

bool Move::jump(){
    if(onGround == true){
        vy = -600;
        onGround = false;
        return true;
    }
    jumped = true;
    return false;
}

int Move::getVX(){ return vx; }

int Move::getAX(){ return ax; }

bool Move::isBeforTowardRight(){ return beforTowardRight; }

void Move::downAccident(){
    vy = 0;
    // cout<<"DOWN ACCIDENT"<<endl;
    onGround = true;
}

void Move::leftAccident(){
    vx = 0;
}

Point Move::returnPreviuseLocation(){
    return previuseLocation;
}

void Move::upAccident(){
    vy = 0;
    // onGround = false;
}

void Move::noAccident(){
    onGround = false;
}

void Move::canJump(){
    onGround = true;
}

void Move::die(){
    lived = false;
}

bool Move::getOnGround(){
    return onGround;
}
#include"Object.h"

#define EMPTY_CELL_CHAR '.'
#define MARIO_CHAR 'M'
#define BRICK_CHAR 'b'
#define BLOCK_COIN_CHAR '?'
#define BLOCK_WITH_MUSHROOM_CHAR 'm'
#define BLOCK_WITH_HEALTH_CHAR 'h'
#define BLOCK_CHAR '@'
#define BLOCK_ON_GROUND_CHAR '#'
#define LITTLE_GOMBA_CHAR 'l'
#define KOPA_CHAR 'k'
#define PIPE_CHAR '|'
#define FLAG_CHAR 'F'

enum TypeCode{
    EMPTY_CELL = 0,
    MARIO,
    BRICK,
    BLOCK_COIN,
    BLOCK_WITH_MUSHROOM,
    BLOCK_WITH_HEALTH,
    BLOCK,
    BLOCK_ON_GROUND,
    LITTLE_GOMBA,
    KOPA,
    PIPE,
    FLAG,
    NUMBER_OFTYPE
};


using namespace std; 

Object::Object():cameraPosition(0,0){}

void Object::updateScreen(Window &window){
    background.show(window, cameraPosition);
    mario.show(window, cameraPosition);
    for(auto block : blocks)
        block.show(window, cameraPosition);
    window.update_screen();
}

void Object::updatePosition(int refreshRate, Window &window){
    mario.updatePosition(refreshRate);
    int center = window.get_width() / 2;
    if( mario.getPosition().x > cameraPosition.x + center)
        cameraPosition.x = mario.getPosition().x - center;
}


bool Object::isMarioOnFlag(){}

void Object::setMario(Point cell){
    mario = Mario(cell);
}

void Object::addBlock(Point cell, int type){
    blocks.push_back(Block(cell, type));
}

void Object::goMarioRight(){
    mario.goRight();
}

void Object::goMarioLeft(){
    mario.goLeft();
}

void Object::stopMario(){ mario.stop(); }

bool Object::isMarioGoLeft(){ return mario.isGoLeft(); }

bool Object::isMarioGoRight(){ return mario.isGoRight(); }

void Object::dontJumpMario(){  mario.dontJump(); }

void Object::jumpMario(){ mario.jump(); }

void Object::fixCrashing(){
    for(auto block : blocks){
        Point topLeft = block.getCell();
        Point downRight(topLeft.x + block.getWidth() , topLeft.y + block.getHeight());
        mario.fixCrashingWithBlock(topLeft, downRight);
    }
}
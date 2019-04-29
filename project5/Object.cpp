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

Object::Object():cameraPosition(0,0){
    coin = 0;
}

void Object::updateScreen(Window &window){
    background.show(window, cameraPosition);
    this->showHeader(window);
    for(auto &littleGomba : littleGombas)
        littleGomba.show(window, cameraPosition);
    for(auto kopa : kopas)
        kopa.show(window, cameraPosition);
    for(auto thisFlag : flag)
        thisFlag.show(window, cameraPosition);
    for(auto pipe : pipes)
        pipe.show(window, cameraPosition);
    for(auto &block : blocks)
        block.show(window, cameraPosition);
    mario.show(window, cameraPosition);
    window.update_screen();
}

void Object::updatePosition(int refreshRate, Window &window){
    mario.updatePosition(refreshRate);
    for(int i = 0 ;i < kopas.size();i++)
        kopas[i].updatePosition(refreshRate, cameraPosition, window);
    for(int i = 0 ;i < littleGombas.size();i++)
        littleGombas[i].updatePosition(refreshRate, cameraPosition, window);
    for(int i = 0 ;i < blocks.size(); i++)
        blocks[i].mushroomUpdatePosition(refreshRate, cameraPosition);
    int center = window.get_width() / 2;
    if( mario.getPosition().x > cameraPosition.x + center)
        cameraPosition.x = mario.getPosition().x - center;
}


bool Object::isMarioOnFlag(){
    Accident accident;
    for(auto thisflag : flag)
        if(accident.check(mario.getRectangle(), thisflag.getRectangle()))
            return true;
    return false;
}

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

bool Object::jumpMario(){ return mario.jump(); }

void Object::fixCrashing(){
    Accident accident;
    int bestType = 0, onGround = 0;
    Rectangle position = mario.getRectangle();
    position = Rectangle(Point(position.x,position.y),position.w,position.h + 1);
    for(auto pipe : pipes){
        Rectangle rectangleFlag = pipe.getRectangle();
        Point topLeft(rectangleFlag.x, rectangleFlag.y);
        Point downRight(topLeft.x + rectangleFlag.w - 1, topLeft.y + rectangleFlag.h - 1);
        onGround |= accident.check(position, rectangleFlag);
        int typeOfAccident = mario.fixCrashingWithBlock(topLeft, downRight);    
        bestType = max(bestType, typeOfAccident);
        for(int  i = 0 ;i < kopas.size() ; i++)
            kopas[i].fixCrashingWithBlock(topLeft, downRight);
        for(int  i = 0 ;i < littleGombas.size() ; i++)
            littleGombas[i].fixCrashingWithBlock(topLeft, downRight);
        for(int  i = 0 ;i < blocks.size(); i++)
            blocks[i].mushroomFixCrashing(topLeft, downRight);
        position = mario.getRectangle();
        position = Rectangle(Point(position.x,position.y),position.w,position.h + 1);
    }
    for(int i = 0; i < blocks.size(); i++){
        Point topLeft = blocks[i].getCell();
        Point downRight(topLeft.x + blocks[i].getWidth() , topLeft.y + blocks[i].getHeight());
        int typeOfAccident = mario.fixCrashingWithBlock(topLeft, downRight);
        if(typeOfAccident == 3){
            coin += blocks[i].accident();
        }
        onGround |= accident.check(position, Rectangle(topLeft,downRight));
        bestType = max(bestType, typeOfAccident);
        for(int  i = 0 ;i < kopas.size() ; i++)
            kopas[i].fixCrashingWithBlock(topLeft, downRight);
        for(int  i = 0 ;i < littleGombas.size() ; i++)
            littleGombas[i].fixCrashingWithBlock(topLeft, downRight);
        for(int  i = 0 ;i < blocks.size(); i++)
            blocks[i].mushroomFixCrashing(topLeft, downRight);
        position = mario.getRectangle();
        position = Rectangle(Point(position.x,position.y),position.w,position.h + 1);
    }
    
    
    for(int i = 0; i < kopas.size(); i++){
        Rectangle rectangle = kopas[i].getRectangle();
        Point topLeft(rectangle.x, rectangle.y);
        Point downRight(rectangle.x + rectangle.w - 1 , rectangle.y + rectangle.h - 1);
        int typeOfAccident = mario.fixCrashingWithBlock(topLeft, downRight);
        bestType = max(bestType, typeOfAccident);
        if(typeOfAccident == 1 || typeOfAccident == 3){
            if(mario.isBig())
                mario.goLittle();
            else
                mario.die();
        }
             
        // else if(typeOfAccident == 2)
        //      kopas[i].die();
        position = mario.getRectangle();
        position = Rectangle(Point(position.x,position.y),position.w,position.h + 1);
    }

    for(int i = 0; i < littleGombas.size(); i++){
        Rectangle rectangle = littleGombas[i].getRectangle();
        Point topLeft(rectangle.x, rectangle.y);
        Point downRight(rectangle.x + rectangle.w - 1 , rectangle.y + rectangle.h - 1);
        if(littleGombas[i].isOnline() == false)
            continue;
        int typeOfAccident = mario.fixCrashingWithBlock(topLeft, downRight);
        bestType = max(bestType, typeOfAccident);
        if(typeOfAccident == 1 || typeOfAccident == 3){
             if(mario.isBig())
                mario.goLittle();
            else
                mario.die();
        }else if(typeOfAccident == 2 && littleGombas[i].isOnline())
             littleGombas[i].die();
        position = mario.getRectangle();
        position = Rectangle(Point(position.x,position.y),position.w,position.h + 1);
    }
    for(int i = 0; i < blocks.size(); i++){
        Rectangle rectangle = blocks[i].getMushroomRectangle();
        Point topLeft(rectangle.x, rectangle.y);
        Point downRight(rectangle.x + rectangle.w - 1 , rectangle.y + rectangle.h - 1);
        int typeOfAccident = mario.fixCrashingWithBlock(topLeft, downRight);
        if(typeOfAccident != 0){
            mario.goBig();
            // cout<<"OK"<<endl;
            blocks[i].mushroomOffline();
        }
    }
    mario.cantJump();
    if(onGround)
        mario.canJump();

}

void Object::addPipe(Point position, int type){
    pipes.push_back(Pipe(position, type));
}

void Object::addFlag(Point position, int type){
    flag.push_back(Flag(position, type));
}

void Object::addKopa(Point position){
    kopas.push_back(Kopa(position));
}

bool Object::checkGameOver(Window &window){
    Point marioPosition = mario.getPosition();
    if(marioPosition.y > window.get_height())
        return true;
    return false;   
}

void Object::addLittleGomba(Point position){
    littleGombas.push_back(LittleGomba(position));
}

void Object::showHeader(Window &window){
    Rectangle destination (Point(0,0), window.get_width(), 40);
    window.fill_rect(destination, RGB(28, 57, 187));
    string coinString = to_string(coin);
    coinString = "Coin : " + coinString;
    window.show_text(coinString, Point(15, 10), WHITE, "FreeSans.ttf", 15);
}
#include"Mario.h"

#define MARIO_SOURCE_IMAGE_RIGHT "assets/sprites/mario/normal/walking-right-1.png"
#define MARIO_SOURCE_IMAGE_LEFT "assets/sprites/mario/normal/walking-left-1.png"
#define MARIO_SOURCE_IMAGE_STANDING_LEFT "assets/sprites/mario/normal/standing-left.png"
#define MARIO_SOURCE_IMAGE_STANDING_RIGHT "assets/sprites/mario/normal/standing-right.png"
using namespace std;

Mario::Mario(): position(0,0), lastTimeImageUpdate(SDL_GetTicks()){}

Mario::Mario(Point cell): position(cell){ 
    marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_RIGHT;
    width = 24, height = ObjectCode::DEFAULT_HEIGHT;
}

void Mario::show(Window &window, Point cameraPosition){
    Rectangle rectangle(position - cameraPosition, 24, 32);
    if(movement.getVX() > 0)
        marioSourceImage = MARIO_SOURCE_IMAGE_RIGHT;
    else if(movement.getVX() < 0)
        marioSourceImage = MARIO_SOURCE_IMAGE_LEFT;
    else{
        if(movement.getAX() > 0)
            marioSourceImage = MARIO_SOURCE_IMAGE_RIGHT;
        else if(movement.getAX() < 0)
            marioSourceImage = MARIO_SOURCE_IMAGE_LEFT;
        else if(movement.isBeforTowardRight() == true)
            marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_RIGHT;
        else
            marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_LEFT;
    }
    window.draw_img(marioSourceImage, rectangle);
}

void Mario::goRight(){ movement.goRight(); }

void Mario::goLeft(){ movement.goLeft(); }

void Mario::stop(){ movement.stop(); }

void Mario::updatePosition(int refreshRate){ position = movement.updatePosition(refreshRate, position); }

Point Mario::getPosition(){ return position; }

bool Mario::isGoLeft(){ return movement.isGoLeft(); }

bool Mario::isGoRight(){ return movement.isGoRight(); }

void Mario::dontJump(){ movement.dontJump(); }

void Mario::jump(){ movement.jump(); }

void Mario::fixCrashingWithBlock(Point topLeft, Point downRight){
    // cout<< position.x << " "<< position.y<< " " ;
    Point marioTopLeft = position, marioDownRight = Point(position.x + width, position.y + height);
    Crash crash(marioTopLeft, marioDownRight, topLeft, downRight);
    Point newPosition = crash.downAccident();
    if(newPosition.x != position.x || newPosition.y != position.y){
        movement.downAccident();
        position = newPosition;
    }
    // cout<< position.x << " " << position.y<< endl;
    // string s;
    // cin>>s;
}
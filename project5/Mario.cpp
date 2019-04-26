#include"Mario.h"

#define MARIO_SOURCE_IMAGE_RIGHT "assets/sprites/mario/normal/walking-right-1.png"
#define MARIO_SOURCE_IMAGE_LEFT "assets/sprites/mario/normal/walking-left-1.png"
#define MARIO_SOURCE_IMAGE_STANDING_LEFT "assets/sprites/mario/normal/standing-left.png"
#define MARIO_SOURCE_IMAGE_STANDING_RIGHT "assets/sprites/mario/normal/standing-right.png"
using namespace std;

Mario::Mario(): position(0,0), lastTimeImageUpdate(SDL_GetTicks()), movement(Point(0,0)){}

Mario::Mario(Point cell)
    : position(cell), movement(cell), lastTimeImageUpdate(SDL_GetTicks()){ 
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

bool Mario::jump(){ return movement.jump(); }

void Mario::fixCrashingWithBlock(Point topLeft, Point downRight){
    // cout<< position.x << " "<< position.y<< " " ;
    Point marioTopLeft = position, marioDownRight = Point(position.x + width - 1, position.y + height - 1);
    Point previusePosition = movement.returnPreviuseLocation();
    Rectangle deltaX(Point(position.x,previusePosition.y),width,height);
    Accident accident;
    if(accident.check(deltaX, Rectangle(topLeft,downRight))){
        position.x = previusePosition.x;
        movement.leftAccident();
    }
    Rectangle deltaY(Point(position.x,position.y),width,height);
    if(accident.check(deltaY, Rectangle(topLeft,downRight))){
        if(position.y > previusePosition.y)
            movement.downAccident();
        else 
            movement.upAccident();
        position.y = previusePosition.y;
    }
    // Crash crash(movement.returnPreviuseLocation(), marioTopLeft, marioDownRight, topLeft, downRight);
    // Point newPosition = crash.downAccident();
    // Point leftCrashPosition = crash.leftAccident();
    // Point upCrashPosition = crash.upAccident();
    // Point rightCrashPosition = crash.righAccident();
    // if(leftCrashPosition.x != position.x || leftCrashPosition.y != position.y){
    //     cout<<"LEFT"<<endl;
    //     movement.leftAccident();
    //     cout<<leftCrashPosition.x<<" "<<leftCrashPosition.y<<" "<<position.x<<" "<<position.y<<endl;
    //     position = leftCrashPosition;
         
    // }else if(rightCrashPosition.x != position.x || rightCrashPosition.y != position.y){
    //     cout<<"Right"<<endl;
    //     movement.leftAccident();
    //     cout<<leftCrashPosition.x<<" "<<leftCrashPosition.y<<" "<<position.x<<" "<<position.y<<endl;
    //     position = rightCrashPosition;
         
    // }else if(newPosition.x != position.x || newPosition.y != position.y){
    //     // cout<<"DOWN"<<endl;
    //     // cout<<newPosition.x<<" "<<newPosition.y<<" "<<position.x<<" "<<position.y<<endl;
    //     movement.downAccident();
    //     position = newPosition;
    // }else if(upCrashPosition.x != position.x || upCrashPosition.y != position.y){
    //     // cout<<"UP"<<endl;
    //     // cout<<upCrashPosition.x<<" "<<upCrashPosition.y<<" "<<position.x<<" "<<position.y<<endl;
    //     movement.upAccident();
    //     position = upCrashPosition;
    // }
    

    // cout<< position.x << " " << position.y<< endl;
    // string s;
    // cin>>s;
}

Rectangle Mario::getRectangle(){
    return Rectangle(position, width, height);
}
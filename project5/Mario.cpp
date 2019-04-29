#include"Mario.h"

#define MARIO_SOURCE_IMAGE_RIGHT "assets/sprites/mario/normal/walking-right-1.png"
#define MARIO_SOURCE_IMAGE_LEFT "assets/sprites/mario/normal/walking-left-1.png"
#define MARIO_SOURCE_IMAGE_STANDING_LEFT "assets/sprites/mario/normal/standing-left.png"
#define MARIO_SOURCE_IMAGE_STANDING_RIGHT "assets/sprites/mario/normal/standing-right.png"
#define MARIO_SOURCE_IMAGE_JUMP_RIGHT "assets/sprites/mario/normal/jumping-right.png"
#define MARIO_SOURCE_IMAGE_JUMP_LEFT "assets/sprites/mario/normal/jumping-left.png"
using namespace std;

Mario::Mario(): position(0,0), lastTimeImageUpdate(SDL_GetTicks()), movement(Point(0,0), 200){}

Mario::Mario(Point cell)
    : position(cell), movement(cell, 200), lastTimeImageUpdate(SDL_GetTicks()){ 
    marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_RIGHT;
    width = 24, height = ObjectCode::DEFAULT_HEIGHT;
}

void Mario::show(Window &window, Point cameraPosition){
    Rectangle rectangle(position - cameraPosition, 24, 32);
    if(movement.getVX() > 0){
        if(movement.getOnGround() == false)
            marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_RIGHT;
        else
            marioSourceImage = MARIO_SOURCE_IMAGE_RIGHT;
    }else if(movement.getVX() < 0){
        if(movement.getOnGround() == false)
            marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_LEFT;
        else
            marioSourceImage = MARIO_SOURCE_IMAGE_LEFT;
    }else{
        if(movement.getOnGround() == false){
            if(movement.isBeforTowardRight() == true)
                marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_RIGHT;
            else
                marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_LEFT;
        }else{
            if(movement.getAX() > 0)
                marioSourceImage = MARIO_SOURCE_IMAGE_RIGHT;
            else if(movement.getAX() < 0)
                marioSourceImage = MARIO_SOURCE_IMAGE_LEFT;
            else if(movement.isBeforTowardRight() == true)
                marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_RIGHT;
            else
                marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_LEFT;
        }
        
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

bool Mario::jump(){ 
    cout<<movement.getOnGround()<<endl;
    return movement.jump();
    
 }

int Mario::fixCrashingWithBlock(Point topLeft, Point downRight){
    if(lived == false)
        return 0;
    // cout<< position.x <<- " "<< position.y<< " " ;
   // cout<<movement.vx<<" "<<movement.vy<<endl;
    int typeOfAccident = 0;
    Point marioTopLeft = position, marioDownRight = Point(position.x + width - 1, position.y + height - 1);
    Point previusePosition = movement.returnPreviuseLocation();
    Rectangle deltaX(Point(position.x,previusePosition.y),width,height);
    Accident accident;
    if(accident.check(deltaX, Rectangle(topLeft,downRight))){
        if(position.x >= previusePosition.x){
            position.x = topLeft.x - width;
            cout<<"LEFTACCIDENT"<<endl;
        }else{
            cout<<"RIGHACCIDENT"<<endl;
            position.x = downRight.x + 1 ;
        }
        // movement.leftAccident();
        typeOfAccident = 1;
    }
    Rectangle deltaY(Point(position.x,position.y),width,height);
    if(accident.check(deltaY, Rectangle(topLeft,downRight))){
        // cout<<"OK"<<endl;
        if(position.y >= previusePosition.y){
            movement.downAccident();
            position.y = topLeft.y - height;
            typeOfAccident = 2;
            // cout<<"OK"<<endl;
        }else {
            // cout<<"OK"<<endl;
            position.y = downRight.y + 1;
            movement.upAccident();
            typeOfAccident = 3;
        }
    }
    // }else
    //     typeOfAccident = 2;
    //cout<<movement.vx<<" "<<movement.vy<<endl;

    return typeOfAccident;
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

void Mario::canJump(){
   // movement.downAccident();
   movement.canJump();
}

void Mario::cantJump(){
    movement.noAccident();
}

bool Mario::stoped(){
    int y1 = (movement.returnPreviuseLocation()).y;
    int y2 = position.y;
    return y1 == y2;
}

void Mario::die(){
    lived = false;
    this->jump();
    movement.die();
}
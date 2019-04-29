#include"Mario.h"

#define MARIO_SOURCE_IMAGE_RIGHT_1 "assets/sprites/mario/normal/walking-right-1.png"
#define MARIO_SOURCE_IMAGE_RIGHT_2 "assets/sprites/mario/normal/walking-right-2.png"
#define MARIO_SOURCE_IMAGE_RIGHT_3 "assets/sprites/mario/normal/walking-right-3.png"
#define MARIO_SOURCE_IMAGE_LEFT_1 "assets/sprites/mario/normal/walking-left-1.png"
#define MARIO_SOURCE_IMAGE_LEFT_2 "assets/sprites/mario/normal/walking-left-2.png"
#define MARIO_SOURCE_IMAGE_LEFT_3 "assets/sprites/mario/normal/walking-left-3.png"
#define MARIO_SOURCE_IMAGE_STANDING_LEFT "assets/sprites/mario/normal/standing-left.png"
#define MARIO_SOURCE_IMAGE_STANDING_RIGHT "assets/sprites/mario/normal/standing-right.png"
#define MARIO_SOURCE_IMAGE_JUMP_RIGHT "assets/sprites/mario/normal/jumping-right.png"
#define MARIO_SOURCE_IMAGE_JUMP_LEFT "assets/sprites/mario/normal/jumping-left.png"

#define BIG_MARIO_SOURCE_IMAGE_RIGHT_1 "assets/sprites/mario/normal/walking-right-1.png"
#define BIG_MARIO_SOURCE_IMAGE_RIGHT_2 "assets/sprites/mario/normal/walking-right-2.png"
#define BIG_MARIO_SOURCE_IMAGE_RIGHT_3 "assets/sprites/mario/normal/walking-right-3.png"
#define BIG_MARIO_SOURCE_IMAGE_LEFT_1 "assets/sprites/mario/normal/walking-left-1.png"
#define BIG_MARIO_SOURCE_IMAGE_LEFT_2 "assets/sprites/mario/normal/walking-left-2.png"
#define BIG_MARIO_SOURCE_IMAGE_LEFT_3 "assets/sprites/mario/normal/walking-left-3.png"
#define BIG_MARIO_SOURCE_IMAGE_STANDING_LEFT "assets/sprites/mario/big/standing-left.png"
#define BIG_MARIO_SOURCE_IMAGE_STANDING_RIGHT "assets/sprites/mario/big/standing-right.png"
#define BIG_MARIO_SOURCE_IMAGE_JUMP_RIGHT "assets/sprites/mario/big/jumping-right.png"
#define BIG_MARIO_SOURCE_IMAGE_JUMP_LEFT "assets/sprites/mario/big/jumping-left.png"


using namespace std;

Mario::Mario(): position(0,0), lastTimeImageUpdate(SDL_GetTicks()), movement(Point(0,0), 200){

    sourceLeftWalking = PictureChanger(vector<string>({MARIO_SOURCE_IMAGE_LEFT_1, 
                    MARIO_SOURCE_IMAGE_LEFT_2, MARIO_SOURCE_IMAGE_LEFT_3}), 300);
    sourceRightWalking = PictureChanger(vector<string>({MARIO_SOURCE_IMAGE_RIGHT_1, 
                    MARIO_SOURCE_IMAGE_RIGHT_2, MARIO_SOURCE_IMAGE_RIGHT_3}), 300);
}

Mario::Mario(Point cell)
    : position(cell), movement(cell, 200), lastTimeImageUpdate(SDL_GetTicks()){ 
    marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_RIGHT;
    width = 24, height = ObjectCode::DEFAULT_HEIGHT;
    sourceLeftWalking = PictureChanger(vector<string>({MARIO_SOURCE_IMAGE_LEFT_1, 
                    MARIO_SOURCE_IMAGE_LEFT_2, MARIO_SOURCE_IMAGE_LEFT_3}), 300);
    sourceRightWalking = PictureChanger(vector<string>({MARIO_SOURCE_IMAGE_RIGHT_1, 
                    MARIO_SOURCE_IMAGE_RIGHT_2, MARIO_SOURCE_IMAGE_RIGHT_3}), 300);
    sourceBigLeftWalking = PictureChanger(vector<string>({BIG_MARIO_SOURCE_IMAGE_LEFT_1, 
                    BIG_MARIO_SOURCE_IMAGE_LEFT_2, BIG_MARIO_SOURCE_IMAGE_LEFT_3}), 300);
    sourceBigRightWalking = PictureChanger(vector<string>({BIG_MARIO_SOURCE_IMAGE_RIGHT_1, 
                    BIG_MARIO_SOURCE_IMAGE_RIGHT_2, BIG_MARIO_SOURCE_IMAGE_RIGHT_3}), 300);
}

void Mario::show(Window &window, Point cameraPosition){
    Rectangle rectangle(position - cameraPosition, width, height);
    if(movement.getVX() > 0){
        if(movement.getOnGround() == false){
            if(biged == true)
                marioSourceImage = BIG_MARIO_SOURCE_IMAGE_JUMP_RIGHT;
            else
                marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_RIGHT;
        }else{
            if(biged == true)
                marioSourceImage = sourceBigRightWalking.getImageSource();
            else
                marioSourceImage = sourceRightWalking.getImageSource();
        }
            
    }else if(movement.getVX() < 0){
        if(movement.getOnGround() == false){
            if(biged == true)
                marioSourceImage = BIG_MARIO_SOURCE_IMAGE_JUMP_LEFT;
            else
                marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_LEFT;
        }else{
            if(biged == true)
                marioSourceImage = sourceBigLeftWalking.getImageSource();
            else
                marioSourceImage = sourceLeftWalking.getImageSource();
        }
    }else{
        if(movement.getOnGround() == false){
            if(movement.isBeforTowardRight() == true){
                if(biged == true)
                    marioSourceImage = BIG_MARIO_SOURCE_IMAGE_JUMP_RIGHT;
                else
                    marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_RIGHT;
            }else{
                if(biged == true)
                marioSourceImage = BIG_MARIO_SOURCE_IMAGE_JUMP_LEFT;
                else
                marioSourceImage = MARIO_SOURCE_IMAGE_JUMP_LEFT;
            }
        }else{
            if(movement.getAX() > 0){
                if(biged == true)
                    marioSourceImage = sourceBigRightWalking.getImageSource();
                else
                    marioSourceImage = sourceRightWalking.getImageSource();
            }else if(movement.getAX() < 0){
                if(biged == true)
                    marioSourceImage = sourceBigLeftWalking.getImageSource();
                else
                    marioSourceImage = sourceLeftWalking.getImageSource();
            }else if(movement.isBeforTowardRight() == true){
                if(biged == true)
                    marioSourceImage = BIG_MARIO_SOURCE_IMAGE_STANDING_RIGHT;
                else 
                    marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_RIGHT;
            }else{
                if(biged == true)
                    marioSourceImage = BIG_MARIO_SOURCE_IMAGE_STANDING_LEFT;
                else 
                    marioSourceImage = MARIO_SOURCE_IMAGE_STANDING_LEFT;
            }
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
    return movement.jump();
    
 }

int Mario::fixCrashingWithBlock(Point topLeft, Point downRight){
    if(lived == false)
        return 0;
    int typeOfAccident = 0;
    Point marioTopLeft = position, marioDownRight = Point(position.x + width - 1, position.y + height - 1);
    Point previusePosition = movement.returnPreviuseLocation();
    Rectangle deltaX(Point(position.x,previusePosition.y),width,height);
    Accident accident;
    if(accident.check(deltaX, Rectangle(topLeft,downRight))){
        if(position.x >= previusePosition.x){
            position.x = topLeft.x - width;
        }else{
            position.x = downRight.x + 1 ;
        }
        typeOfAccident = 1;
    }
    Rectangle deltaY(Point(position.x,position.y),width,height);
    if(accident.check(deltaY, Rectangle(topLeft,downRight))){
        if(position.y >= previusePosition.y){
            movement.downAccident();
            position.y = topLeft.y - height;
            typeOfAccident = 2;
        }else {
            position.y = downRight.y + 1;
            movement.upAccident();
            typeOfAccident = 3;
        }
    }
    return typeOfAccident;
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

void Mario::goBig(){
    if(biged == false){
        position.y -= 34;
    }
    width = 32;
    height = 66;
    biged = true;
}

bool Mario::isBig(){
    return biged;
}

void Mario::goLittle(){
    if(biged == true){
        position.y += 34;
    }
    width = 24;
    height = 32;
    biged = false;
}
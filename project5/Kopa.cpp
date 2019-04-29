#include"Kopa.h"

#define SOURCE_IMAGE_KOPA_1 "assets/sprites/enemies/koopa_troopa/walking-left-1.png"
#define SOURCE_IMAGE_KOPA_2 "assets/sprites/enemies/koopa_troopa/walking-left-2.png"
#define DELAY_TIME 300
#define WIDTH 24
#define HEIGHT 32

using namespace std;

Kopa::Kopa(Point _position):position(_position), movement(_position,  120){
    sourceImage = PictureChanger(vector<string>({SOURCE_IMAGE_KOPA_1, SOURCE_IMAGE_KOPA_2}), DELAY_TIME);
    width = WIDTH, height = HEIGHT;
}

void Kopa::show(Window &window, Point cameraPosition){
    Point cell(position.x - cameraPosition.x, position.y);
    window.draw_img(sourceImage.getImageSource(),Rectangle(cell, width, height));
}

void Kopa::goLeft(){
    movement.goLeft();
}

void Kopa::goRight(){
    movement.goRight();
}

void Kopa::updatePosition(int refreshrate, Point cameraPosition, Window &window){
    position = movement.updatePosition(refreshrate, position);
    // cout<<position.x << " "<<cameraPosition.x<<endl;
    if(position.x < cameraPosition.x + window.get_width())
        movement.goLeft();
}

void Kopa::fixCrashingWithBlock(Point topLeft,Point downRight){
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
        if(position.y > previusePosition.y){
            movement.downAccident();
            position.y = topLeft.y - height;
        }else {
            position.y = downRight.y + 1;
            movement.upAccident();
        }
            
       
    }
}

Rectangle Kopa::getRectangle(){
    return Rectangle(position, width, height);
}
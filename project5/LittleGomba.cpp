#include"LittleGomba.h"

using namespace std;

#define SOURCE_IMAGE_WALKING_GOMBA_1 "assets/sprites/enemies/little_goomba/walking-1.png"
#define SOURCE_IMAGE_WALKING_GOMBA_2 "assets/sprites/enemies/little_goomba/walking-2.png"
#define SOURCE_IMAGE_DIE_LITTLE_GOMBA "assets/sprites/enemies/little_goomba/dead.png"


LittleGomba::LittleGomba(Point _position):position(_position),movement(_position, 120){
    sourceImage = PictureChanger(vector<string>({SOURCE_IMAGE_WALKING_GOMBA_1, SOURCE_IMAGE_WALKING_GOMBA_2}), 300);
}

void LittleGomba::show(Window &window, Point cameraPosition){
    Point realPosition(position.x - cameraPosition.x, position.y);
    // cout<<"OK"<<endl;
    window.draw_img(sourceImage.getImageSource(), Rectangle(realPosition, 32, 32));
}


void LittleGomba::goLeft(){
    movement.goLeft();
}

void LittleGomba::goRight(){
    movement.goRight();
}

void LittleGomba::updatePosition(int refreshrate, Point cameraPosition, Window &window){
    if(lived == false)
        return;
    position = movement.updatePosition(refreshrate, position);
    // cout<<position.x << " "<<cameraPosition.x<<endl;
    if(position.x < cameraPosition.x + window.get_width() && stoped == true){
        movement.goLeft();
        stoped = false;
    }
        
}

void LittleGomba::fixCrashingWithBlock(Point topLeft,Point downRight){
    Point marioTopLeft = position, marioDownRight = Point(position.x + 24 - 1, position.y + 32 - 1);
    Point previusePosition = movement.returnPreviuseLocation();
    Rectangle deltaX(Point(position.x,previusePosition.y),24,32);
    Accident accident;
    if(accident.check(deltaX, Rectangle(topLeft,downRight))){
        if(previusePosition.x < position.x)
            movement.goLeft();
        else
            movement.goRight();
        position.x = previusePosition.x;
        movement.leftAccident();
    }
    Rectangle deltaY(Point(position.x,position.y),24,32);
    if(accident.check(deltaY, Rectangle(topLeft,downRight))){
        if(position.y > previusePosition.y){
            movement.downAccident();
            position.y = topLeft.y - 32;
        }else {
            position.y = downRight.y + 1;
            movement.upAccident();
        }
            
       
    }
}


Rectangle LittleGomba::getRectangle(){
    return Rectangle(position, 32, 32);
}

void LittleGomba::die(){
    lived = false;
    cout<<"OK"<<endl;
    sourceImage = PictureChanger(vector<string>({SOURCE_IMAGE_DIE_LITTLE_GOMBA}), 300);
}

bool LittleGomba::isOnline(){
    return lived;
}
#include"MushRoom.h"

#define MUSHROOM_SOURCE_IMAGE "assets/sprites/objects/mushroom/red.png"
#define REFRESH_RATE 30
#define MUSHROOM_COUNTER 32
#define MUSHROOM_WIDTH 32
#define MUSHROOM_HEIGHT 32

using namespace std;

MushRoom::MushRoom(Point point, bool _online):position(point), online(_online), movement(point, 120){
    counter = MUSHROOM_COUNTER;
}

void MushRoom::show(Window &window, Point cameraPosition){
    if(die == true)
        return;
    if(online == false)
        return;
    if(counter > 0){
        counter--;
        Rectangle destination ( Point(position.x - cameraPosition.x, position.y - (MUSHROOM_HEIGHT - counter)),
                                 MUSHROOM_WIDTH, MUSHROOM_HEIGHT);
        window.draw_img(MUSHROOM_SOURCE_IMAGE, destination);
        if(counter == 0)
            movement.goRight();
    }else if(counter == 0){
       Rectangle destination( Point(position.x - cameraPosition.x, position.y), MUSHROOM_WIDTH, MUSHROOM_HEIGHT);
       window.draw_img(MUSHROOM_SOURCE_IMAGE, destination);
    }
}

void MushRoom::fixCrashing(Point topLeft, Point downRight){
    if(die == true)
        return;
    if(online == false || counter > 0)
        return;
    Point marioTopLeft = position, marioDownRight = Point(position.x + MUSHROOM_WIDTH - 1, position.y + MUSHROOM_HEIGHT - 1);
    Point previusePosition = movement.returnPreviuseLocation();
    Rectangle deltaX(Point(position.x,previusePosition.y),MUSHROOM_WIDTH,MUSHROOM_HEIGHT);
    Accident accident;
    if(accident.check(deltaX, Rectangle(topLeft,downRight))){
        if(previusePosition.x < position.x)
            movement.goLeft();
        else
            movement.goRight();
        position.x = previusePosition.x;
        movement.leftAccident();
    }
    Rectangle deltaY(Point(position.x,position.y),MUSHROOM_WIDTH,MUSHROOM_HEIGHT);
    if(accident.check(deltaY, Rectangle(topLeft,downRight))){
        if(position.y >= previusePosition.y){
            movement.downAccident();
            position.y = topLeft.y - MUSHROOM_HEIGHT;
        }else {
            position.y = downRight.y + 1;
            movement.upAccident();
        }
    }
}

void MushRoom::updatePosition(int refreshRate, Point cameraPosition){
    if(online == true && counter==0)
        position = movement.updatePosition(REFRESH_RATE, position);
}

Rectangle MushRoom::getRectangle(){
    if(online == true && die == false)
        return Rectangle(position, MUSHROOM_WIDTH, MUSHROOM_HEIGHT);
    else 
        return Rectangle(Point(0,0), 1,1);
}

void MushRoom::offline(){
    die = true;
    online = false;
}
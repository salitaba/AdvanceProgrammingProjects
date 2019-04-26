#include"Flag.h"

#define FLAG_SOURCE_IMAGE "assets/sprites/objects/flag/body.png"
#define TOP_FLAG_SOURCE_IMAGE "assets/sprites/objects/flag/head.png"

using namespace std;

Flag::Flag():position(Point(0,0)){}

Flag::Flag(Point _position, int _type):position(_position), type(_type){}

void Flag::show(Window &window, Point cameraPosition){
    Rectangle destinationRectangle(Point(position.x - cameraPosition.x, position.y), 32, 32);
    string sourceImage;
    // cout<<ObjectCode::FLAG<<" "<<type<<" "<<ObjectCode::TOP_FLAG<<endl;
    switch(type){
        case ObjectCode::FLAG :
            sourceImage = FLAG_SOURCE_IMAGE;
            break;
        case ObjectCode::TOP_FLAG :
            sourceImage = TOP_FLAG_SOURCE_IMAGE;
            break;
    }
    // cout<<sourceImage<<endl;
    window.draw_img(sourceImage, destinationRectangle);
}

Rectangle Flag::getRectangle(){
    return Rectangle(position,32,32);
}
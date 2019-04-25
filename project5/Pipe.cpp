#include"Pipe.h"

#define PIPE_TOP_LEFT_SOURCE_IMAGE "assets/sprites/objects/pipe/head-left.png"
#define PIPE_TOP_RIGHT_SOURCE_IMAGE "assets/sprites/objects/pipe/head-right.png"
#define PIPE_LEFT_SOURCE_IMAGE "assets/sprites/objects/pipe/left.png"
#define PIPE_RIGHT_SOURCE_IMAGE "assets/sprites/objects/pipe/right.png"

using namespace std;

Pipe::Pipe(Point _position, int _type): position(_position),type(_type){}

void Pipe::show(Window &window,Point cameraPosition){
    Rectangle destinationRectangle(Point(position.x - cameraPosition.x, position.y), 32, 32);
    string sourceImage;
    switch(type){
        case ObjectCode::PIPE_LEFT :
            sourceImage = PIPE_LEFT_SOURCE_IMAGE;
            break;
        case ObjectCode::PIPE_RIGHT :
            sourceImage = PIPE_RIGHT_SOURCE_IMAGE;
            break;
        case ObjectCode::PIPE_TOP_LEFT :
            sourceImage = PIPE_TOP_LEFT_SOURCE_IMAGE;
            break;
        case ObjectCode::PIPE_TOP_RIGHT :
            sourceImage = PIPE_TOP_RIGHT_SOURCE_IMAGE;
            break;
    }
    window.draw_img(sourceImage, destinationRectangle);
}
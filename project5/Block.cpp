#include"Block.h"

#define BLOCK_ON_GROUND_IMAGE "assets/sprites/objects/bricks_blocks/clay.png"
#define BRICK_SOURCE_IMAGE "assets/sprites/objects/bricks_blocks/brick.png"
#define BLOCK_COIN_IMAGE "assets/sprites/objects/bricks_blocks/question-1.png"
#define BLOCK_QUESTION_IMAGE "assets/sprites/objects/bricks_blocks/question-1.png"
#define BLOCK_IMAGE "assets/sprites/objects/bricks_blocks/block.png"

using namespace std;

Block::Block(Point _cell, int _type):type(_type), cell(_cell){
    switch(type){
        case ObjectCode::BLOCK_ON_GROUND_CHAR:
            sourceImage = BLOCK_ON_GROUND_IMAGE ;
            break;
        case ObjectCode::BRICK_CHAR:
            sourceImage = BRICK_SOURCE_IMAGE;
            break;
        case ObjectCode::BLOCK_COIN_CHAR:
            sourceImage = BLOCK_QUESTION_IMAGE;
            break;
        case ObjectCode::BLOCK_WITH_MUSHROOM_CHAR:
            sourceImage = BLOCK_QUESTION_IMAGE;
            break;
        case ObjectCode::BLOCK_WITH_HEALTH_CHAR:
            sourceImage = BLOCK_QUESTION_IMAGE;
            break;
        case ObjectCode::BLOCK_CHAR:
            sourceImage = BLOCK_IMAGE;
    }
    width = ObjectCode::DEFAULT_WIDTH, height = ObjectCode::DEFAULT_HEIGHT;
}

void Block::show(Window &window, Point cameraPosition){
    Rectangle destinationRectangle(cell - cameraPosition, 32, 32);
    window.draw_img(sourceImage, destinationRectangle); 
}

Point Block::getCell(){
    return cell;
}

int Block::getWidth(){
    return width;
}

int Block::getHeight(){
    return height;
}
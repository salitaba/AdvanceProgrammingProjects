#include"Block.h"

#define BLOCK_ON_GROUND_IMAGE "assets/sprites/objects/bricks_blocks/clay.png"
#define BRICK_SOURCE_IMAGE "assets/sprites/objects/bricks_blocks/brick.png"
#define BLOCK_COIN_IMAGE "assets/sprites/objects/bricks_blocks/question-1.png"
#define BLOCK_QUESTION_IMAGE_1 "assets/sprites/objects/bricks_blocks/question-1.png"
#define BLOCK_QUESTION_IMAGE_2 "assets/sprites/objects/bricks_blocks/question-2.png"
#define BLOCK_QUESTION_IMAGE_3 "assets/sprites/objects/bricks_blocks/question-3.png"
#define BLOCK_IMAGE "assets/sprites/objects/bricks_blocks/block.png"
#define BLOCK_EMPTY_QUESTION_IMAGE "assets/sprites/objects/bricks_blocks/question-empty.png"
#define DELAY_TIME 400
using namespace std;

Block::Block(Point _cell, int _type):type(_type), cell(_cell),coin(_cell,false){
    questionSourceImage = PictureChanger(vector<string>({
        BLOCK_QUESTION_IMAGE_1, BLOCK_QUESTION_IMAGE_2, BLOCK_QUESTION_IMAGE_3}), DELAY_TIME);
    width = ObjectCode::DEFAULT_WIDTH, height = ObjectCode::DEFAULT_HEIGHT;
}

void Block::show(Window &window, Point cameraPosition){
    switch(type){
        case ObjectCode::BLOCK_ON_GROUND_CHAR:
            sourceImage = BLOCK_ON_GROUND_IMAGE ;
            break;
        case ObjectCode::BRICK_CHAR:
            sourceImage = BRICK_SOURCE_IMAGE;
            break;
        case ObjectCode::BLOCK_COIN_CHAR:
            sourceImage = questionSourceImage.getImageSource();            
            break;
        case ObjectCode::BLOCK_WITH_MUSHROOM_CHAR:
            sourceImage = questionSourceImage.getImageSource();
            break;
        case ObjectCode::BLOCK_WITH_HEALTH_CHAR:
            sourceImage = questionSourceImage.getImageSource();
            break;
        case ObjectCode::BLOCK_CHAR:
            sourceImage = BLOCK_IMAGE;
            break;
        case ObjectCode::EMPTY_QUESTION_CHAR:
            sourceImage = questionSourceImage.getImageSource();
            coin.show(window, cameraPosition);
            break;
    }
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

bool Block::accident(){
    // this->jump();
    switch(type){
        case ObjectCode::BLOCK_COIN_CHAR :
            questionSourceImage = PictureChanger(vector<string>({BLOCK_EMPTY_QUESTION_IMAGE}), 300);
            type = ObjectCode::EMPTY_QUESTION_CHAR;
            //cout<<"COIN ACCIDENT"<<endl;
            coin = Coin(cell, true);
            break;  
    }
}
#ifndef OBJECT_CODE_H
#define OBJECT_CODE_H

#include<string>
#include<vector>

class ObjectCode{
public:
    ObjectCode();
    int getCode(std::string object);
    enum Code{
        EMPTY_CELL = 0,
        MARIO,
        BRICK,
        BLOCK_COIN,
        BLOCK_WITH_MUSHROOM,
        BLOCK_WITH_HEALTH,
        BLOCK,
        BLOCK_ON_GROUND,
        LITTLE_GOMBA,
        KOPA,
        PIPE,
        FLAG,
        TOP_FLAG,
        PIPE_LEFT,
        PIPE_RIGHT,
        PIPE_TOP_LEFT,
        PIPE_TOP_RIGHT,
        NUMBER_OFTYPE,
        
    };

    enum Char{
        EMPTY_CELL_CHAR = '.',
        MARIO_CHAR = 'M',
        BRICK_CHAR = 'b',
        BLOCK_COIN_CHAR = '?',
        BLOCK_WITH_MUSHROOM_CHAR = 'm',
        BLOCK_WITH_HEALTH_CHAR = 'h',
        BLOCK_CHAR = '@',
        BLOCK_ON_GROUND_CHAR = '#',
        LITTLE_GOMBA_CHAR = 'l',
        KOPA_CHAR = 'k',
        PIPE_CHAR = '|',
        FLAG_CHAR = 'f',
        DEFAULT_WIDTH = 32,
        DEFAULT_HEIGHT = 32,
        NUMBER_OF_CULOMN = 30,
    };
private:
    std::string objects[30];
};
#endif
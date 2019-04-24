#include"ObjectCode.h"

using namespace std;

ObjectCode::ObjectCode(): objects({ "EMPTY_CELL", "MARIO", "BRICK", "BLOCK_COIN", "BLOCK_COIN", 
                "BLOCK_WITH_MUSHROOM", "BLOCK_WITH_HEALTH", "BLOCK", "BLOCK_ON_GROUND",
                "LITTLE_GOMBA", "KOPA", "PIPE", "FLAG" }){}

int ObjectCode::getCode(string object){
    for(int code = 0; code < 30 ;code++)
        if(object == objects[code])
            return code;
}
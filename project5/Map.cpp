#include"Map.h"

using namespace std;

Map::Map(string sourceAddress){
    ifstream sourceMap (sourceAddress);
    string line;
    while(getline(sourceMap, line))
        map.push_back(line);
}

Object Map::createObjects(){
    Object objects;
    for(int i = 0; i < map.size(); i++)
        for(int j = 0; j < map[i].size(); j++){
            Point cell(j * ObjectCode::DEFAULT_WIDTH, i * ObjectCode::DEFAULT_HEIGHT);
            switch(map[i][j]){
                case ObjectCode::EMPTY_CELL_CHAR:
                    break;
                case ObjectCode::MARIO_CHAR:
                    objects.setMario(cell);
                    break;
                case ObjectCode::FLAG_CHAR:
                    break;
                case ObjectCode::LITTLE_GOMBA_CHAR:
                    break;
                case ObjectCode::PIPE_CHAR:
                    if(map[i][j + 1] == ObjectCode::PIPE_CHAR){
                        if(map[i - 1][j] == ObjectCode::PIPE_CHAR){
                            objects.addPipe(cell, ObjectCode::PIPE_LEFT);
                        }else{
                            objects.addPipe(cell, ObjectCode::PIPE_TOP_LEFT);
                        }
                    }else{
                        if(map[i - 1][j] == ObjectCode::PIPE_CHAR){
                            objects.addPipe(cell, ObjectCode::PIPE_RIGHT);
                        }else{
                            objects.addPipe(cell, ObjectCode::PIPE_TOP_RIGHT);
                        }

                    }

                    break;
                case ObjectCode::KOPA_CHAR:
                    break;
                default:
                    objects.addBlock(cell, map[i][j]);
                    break;
            }
        }
    return objects;
}


Window Map::getWindowFitMap(){
    return Window(ObjectCode::DEFAULT_WIDTH * ObjectCode::NUMBER_OF_CULOMN, map.size() * ObjectCode::DEFAULT_HEIGHT);
}






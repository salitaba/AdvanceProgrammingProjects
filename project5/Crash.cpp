#include"Crash.h"

Crash::Crash(Point _topLeft1 ,Point _downRight1,Point _topLeft2,Point _downRight2)
    :  topLeft1(_topLeft1), topLeft2(_topLeft2), downRight1(_downRight1), downRight2(_downRight2){}

bool Crash::leftAccident(){
    return topLeft1.x < topLeft2.x && downRight2.x < downRight1.x && 
        !(topLeft1.y > downRight2.y || topLeft2.y > downRight1.y);
}

bool Crash::righAccident(){
    return topLeft2.x < downRight1.x && topLeft1.x < downRight2.x &&
        !(topLeft1.y > downRight2.y || topLeft2.y > downRight1.y);
}

Point Crash::downAccident(){
    if(downRight1.y > topLeft2.y && topLeft1.y < downRight2.y &&
            !(topLeft1.x > downRight2.x || downRight1.x < topLeft2.x)){
        int height = downRight1.y - topLeft1.y ;
        if(topLeft2.y - height - 1 == 351){
            std::cout<<topLeft2.x << " "<< topLeft2.y << " " << downRight2.x << " " << downRight2.y << std::endl;
        }
        return Point(topLeft1.x,topLeft2.y - height);
    }
    return topLeft1;
}

bool Crash::upAccident(){
    return topLeft1.y < downRight2.y && topLeft2.y < downRight1.y &&
        !(topLeft1.x > downRight2.x || downRight1.x < topLeft2.x);
}
#include"Crash.h"

Crash::Crash(Point _previuseTopLeft, Point _topLeft1 ,Point _downRight1,Point _topLeft2,Point _downRight2)
    :   topLeft1(_topLeft1), topLeft2(_topLeft2), downRight1(_downRight1), downRight2(_downRight2),
        previuseTopLeft(_previuseTopLeft){}

Point Crash::leftAccident(){
    if (topLeft1.x >= topLeft2.x && topLeft1.x <= downRight2.x && 
        !(topLeft1.y > downRight2.y || topLeft1.y < topLeft2.y))
            return Point(previuseTopLeft.x, topLeft1.y);
    return topLeft1;
    // if(previuseTopLeft.x < topLeft1.x)
    //     return topLeft1;
    // if(topLeft1.y > previuseTopLeft.y){
    //     int height = downRight1.y - topLeft1.y;
    //     Line line(Point(previuseTopLeft.x, previuseTopLeft.y + height), Point(topLeft1.x, downRight1.y));
    //     int crashPointY = line.getYWithX(downRight2.x);
    //     if(crashPointY <= downRight2.y && crashPointY >= topLeft2.y && topLeft1.x <= downRight2.x && topLeft1.x >= topLeft2.x
    //         && topLeft1.y >= topLeft2.y && topLeft1.y <= downRight2.y)
    //         // return Point(downRight2.x + 1, crashPointY - height );
    //         return Point(previuseTopLeft.x+2,topLeft1.y);
    //     else
    //         return topLeft1;
    // }else{
    //     Line line(previuseTopLeft, topLeft1);
    //     int crashPointY = line.getYWithX(downRight2.x);
    //     if(crashPointY <= downRight2.y && crashPointY >= topLeft2.y && topLeft1.x <= downRight2.x && topLeft1.x >= topLeft2.x
    //         && topLeft1.y >= topLeft2.y && topLeft1.y <= downRight2.y)
    //         // return Point(downRight2.x + 1, crashPointY);
    //         return Point(previuseTopLeft.x+2,topLeft1.y);
    //     else
    //         return topLeft1;
    // }
}

Point Crash::righAccident(){
    // return topLeft2.x < downRight1.x && topLeft1.x < downRight2.x &&
    //     !(topLeft1.y > downRight2.y || topLeft2.y > downRight1.y);
    int width = downRight1.x - topLeft1.x;
    if(downRight1.x >= topLeft2.x && downRight1.x <= downRight2.x &&
        !(topLeft1.y > downRight2.y || topLeft1.y < topLeft2.y))
        return Point(previuseTopLeft.x, topLeft1.y);
    return topLeft1;
}

Point Crash::downAccident(){
    if(downRight1.y >= topLeft2.y && topLeft1.y <= topLeft2.y &&
            !(topLeft1.x > downRight2.x || downRight1.x < topLeft2.x)){
        int height = downRight1.y - topLeft1.y ;
        return Point(topLeft1.x,topLeft2.y - height);
        // return Point(topLeft1.x,previuseTopLeft.y);
    }
    return topLeft1;
}

Point Crash::upAccident(){
    if( topLeft1.y < downRight2.y && topLeft2.y < downRight1.y &&
        !(topLeft1.x > downRight2.x || downRight1.x < topLeft2.x)){
        //return Point(topLeft1.x, downRight2.y + 1);
        return previuseTopLeft;
        }
    return topLeft1;
}
#include"Line.h"

using namespace std;

Line::Line(Point A, Point B):a(A), b(B){}

int Line::getYWithX(int x){
    if(a.x == b.x)
        return a.y;
    double slope = double(b.y - a.y) / double(b.x - a.x);
    double constance = double(a.y) - slope * a.x;
    return slope * x + constance ;
}

int Line::getXWithY(int y){
    if(a.y == b.y)
        return a.x;
    double slope = double(b.x - a.x) / double(a.y - b.y);
    double constance = double(a.x) - slope * a.y;
    return slope * y + constance;
}

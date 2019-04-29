#include"Accident.h"

using namespace std;

bool Accident::check(Rectangle a, Rectangle b){
    //cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    Point topLeftA(a.x, a.y);
    Point downRightA(a.x + a.w - 1, a.y + a.h - 1);
    if(this->pointAccident(topLeftA, b))
        return true; 
    //cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    if(this->pointAccident(downRightA, b))
        return true;
    //    cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    if(this->pointAccident(Point(topLeftA.x, downRightA.y), b))
        return true;
    //    cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    if(this->pointAccident(Point(downRightA.x, topLeftA.y), b))
        return true;
    //    cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    swap(a,b);
    topLeftA = Point(a.x, a.y);
    downRightA = Point(a.x + a.w - 1, a.y + a.h - 1);
    if(this->pointAccident(topLeftA, b))
        return true; 
    //cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    if(this->pointAccident(downRightA, b))
        return true;
    //    cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    if(this->pointAccident(Point(topLeftA.x, downRightA.y), b))
        return true;
    //    cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    if(this->pointAccident(Point(downRightA.x, topLeftA.y), b))
        return true;
    //    cout<<a.x + a.w<<" "<<a.y<<" "<<b.x<<" "<<b.x + b.w<<" "<<b.y<<" "<<b.y + b.h<<endl;
    return false;
}

bool Accident::pointAccident(Point a, Rectangle b){
    int x1 = b.x, x2 = b.x + b.w - 1, y1 = b.y, y2 = b.y + b.h - 1;
    if(a.x >= x1 && a.x <= x2 && a.y >= y1 && a.y <= y2)
        return true;
    return false;
}
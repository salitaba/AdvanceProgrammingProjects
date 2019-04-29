#include"Coin.h"

#define SOURCE_IMAGE_COIN "assets/sprites/objects/coin.png"


using namespace std;

Coin::Coin(Point point,bool online): position(point){
    if(online == true)
        counter = 32;
    else
        counter = 0;

}

void Coin::show(Window &window, Point cameraPosition){
    if(counter > 0){
        //cout<<"COINT COUNTER "<<counter<<endl;
        Rectangle destination (Point(position.x - cameraPosition.x, position.y - (32 - counter)),32, 32);
        window.draw_img(SOURCE_IMAGE_COIN,destination);
        counter--;
        //cout<<"COIN COUNTER "<<counter<<endl;
    }
    //cout<<counter<<endl;
}
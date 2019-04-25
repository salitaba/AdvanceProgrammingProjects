#include"Background.h"

#define BACKGROUND_PATH "assets/background_image.png"

using namespace std;

Background::Background(){}


void Background::show(Window &window, Point cameraPosition){
    int cnt = 200;
    for(int i= 0 ;i< 200;i++){
        window.draw_img(BACKGROUND_PATH, Rectangle(Point(i * 2000 - cameraPosition.x , 0),
                        Point((i+1) * 2000 - cameraPosition.x,window.get_height())));
    }
}
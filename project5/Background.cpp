#include"Background.h"

#define BACKGROUND_PATH "assets/background_image.png"

using namespace std;

Background::Background(){}


void Background::show(Window &window, Point cameraPosition){
    int nesbat = 2000 / window.get_width();
    cameraPosition.x = cameraPosition.x % window.get_width();
    Rectangle rectangleDestinationLeft(Point(0,0), window.get_width() - cameraPosition.x, window.get_height());
    Rectangle rectangleDestinationRight(Point(window.get_width() - cameraPosition.x, 0), cameraPosition.x, window.get_height());
    Rectangle rectangleSourceLeft(cameraPosition, window.get_width() - cameraPosition.x, 1000);
    Rectangle rectangleSourceRight(Point(0,0), cameraPosition.x , 1000); 
    // cout<< window.get_height()<<" "<<window.get_width()<<endl;
    window.draw_img(BACKGROUND_PATH, rectangleDestinationLeft, rectangleSourceLeft);
    window.draw_img(BACKGROUND_PATH, rectangleDestinationRight, rectangleSourceRight);
}
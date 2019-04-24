#include<iostream>
#include"RSDL/src/rsdl.hpp"
#include"Map.h"
#include"Screen.h"
#include"GameManager.h"

#define SCREEN_REFRESH_RATE 30


using namespace std;
int main(int argc , char* argv[]){
    string s;
    Map map(argv[1]);
    Window window = map.getWindowFitMap();
    GameManager game(map, window, SCREEN_REFRESH_RATE);
    game.start();
}

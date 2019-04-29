#include"PictureChanger.h"

using namespace std;

PictureChanger::PictureChanger(){}

PictureChanger::PictureChanger(vector<string> _sources, int _delayTime):sources(_sources),delayTime(_delayTime){
    startTime = SDL_GetTicks();
}

string PictureChanger::getImageSource(){
    int nowTime = SDL_GetTicks();
    int count = (nowTime - startTime)/delayTime;
    int size = sources.size();
    return sources[count % size];
}
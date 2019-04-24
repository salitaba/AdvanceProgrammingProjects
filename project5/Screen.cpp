#include"Screen.h"

using namespace std;

Screen::Screen(Window &_window):window(_window){}

void Screen::updateScreen(Object objects){
    
    window.update_screen();
}
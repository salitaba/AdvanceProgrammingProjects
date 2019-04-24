#include"GameManager.h"

using namespace std;

GameManager::GameManager(Map map, Window &_window, int _screenRefreshRate) 
    : screen(window), window(_window) ,objects(map.createObjects()), lastTimeScreenUpdate(SDL_GetTicks()){
    screenRefreshRate = _screenRefreshRate;
}

void GameManager::start(){
    bool online = true ;
    while(online == true){
        this->handleEvent();
        objects.updatePosition(screenRefreshRate, window);
        objects.fixCrashing();
        objects.updateScreen(window);
        // objects.isMarioOnFlag()
        while(SDL_GetTicks() - lastTimeScreenUpdate < 30){}
        lastTimeScreenUpdate = SDL_GetTicks();
        
    }
}

void GameManager::handleEvent(){
    while(window.has_pending_event()) {    
        char keyPressed, keyRealized;
        Event event = window.poll_for_event();
        switch(event.get_type()) {
            case Event::QUIT :
                abort();
                break;
            case Event::KEY_RELEASE :
                keyRealized = event.get_pressed_key();
                if( keyRealized == 'd' and objects.isMarioGoRight())
                    objects.stopMario();
                if( keyRealized == 'a' and objects.isMarioGoLeft())
                    objects.stopMario();
                if( keyRealized == 'w')
                    objects.dontJumpMario();
                break;
            case Event::KEY_PRESS :
                keyPressed = event.get_pressed_key();
                if( keyPressed == 'd')
                    objects.goMarioRight();
                if( keyPressed == 'a')
                    objects.goMarioLeft();
                if( keyPressed == 'w')
                    objects.jumpMario();
                break;
        }
    }
}
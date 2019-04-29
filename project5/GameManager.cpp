#include"GameManager.h"

using namespace std;

GameManager::GameManager(Map map, Window &_window, int _screenRefreshRate) 
    : screen(window), window(_window) ,objects(map.createObjects()), lastTimeScreenUpdate(SDL_GetTicks()){
    screenRefreshRate = _screenRefreshRate;
}

void GameManager::start(){
    window.play_music("assets/sounds/Super Mario Bros. theme music.mp3");
    bool online = true ;
    while(online == true){
        window.clear();
        this->handleEvent();
        objects.updatePosition(screenRefreshRate, window);
        objects.fixCrashing();
        objects.updateScreen(window);
        if(objects.checkGameOver(window)){
            window.stop_music();
            window.play_sound_effect("assets/sounds/sound_effects/gameover.wav");
            delay(3000);
            return; 
        }
        if(objects.isMarioOnFlag()){
            //cout<<"OK"<<endl;
            window.stop_music();
            window.play_sound_effect("assets/sounds/sound_effects/level-clear.wav");
            while(true){
                window.show_text("YOU WIN!", Point(window.get_width()/2 - 70, window.get_height()/2 - 10), RED);
                window.update_screen();
                this->handleEvent();
                delay(30);
            }
        }
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
                if( keyPressed == 'w'){
                    if(objects.jumpMario())
                        window.play_sound_effect("assets/sounds/sound_effects/jump-small.wav");
                }   
                   
                break;
        }
    }
}
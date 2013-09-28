#include "CApp.h"
 
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	window = SDL_CreateWindow("Pentagon Invaders",
				SDL_WINDOWPOS_CENTERED ,
				SDL_WINDOWPOS_CENTERED,
				1024, 768,
				SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
 
    if(window == NULL) {
        return false;
    }
 
    return true;
}
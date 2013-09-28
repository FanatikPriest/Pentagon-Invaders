#include "CApp.h"
 
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	sdlWindow = SDL_CreateWindow("Pentagon Invaders",
				SDL_WINDOWPOS_CENTERED ,
				SDL_WINDOWPOS_CENTERED,
				1024, 768,
				SDL_WINDOW_OPENGL);
 
    if(sdlWindow == NULL) {
        return false;
    }

	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

	if(sdlRenderer == NULL) {
        return false;
    }

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);
 
    return true;
}
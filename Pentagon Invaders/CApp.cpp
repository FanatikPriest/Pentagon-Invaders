#include "CApp.h"
 
CApp::CApp() {
	sdlWindow = NULL;
	sdlRenderer = NULL;
    Surf_Display = NULL;
 
    Running = true;

	scene = &Scene::getInstance();
}
 
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}
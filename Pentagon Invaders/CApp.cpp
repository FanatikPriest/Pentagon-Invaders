#include "CApp.h"
 
CApp::CApp() {
	sdlWindow = NULL;
 
    Running = true;

	scene = &Scene::getInstance();
}
 
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event event;
 
    while(Running) {
        while(SDL_PollEvent(&event)) {
            OnEvent(event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}
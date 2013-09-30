#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glut.h>

#include "Scene.h"
 
class CApp {
private:
	bool    Running;

	SDL_Window*		sdlWindow;
	SDL_Renderer*	sdlRenderer;
	SDL_Surface*    Surf_Display;
	SDL_GLContext	glContext;

	Scene scene;
 
public:
    CApp();
 
    int OnExecute();
 
public:
 
    bool OnInit();
 
    void OnEvent(SDL_Event* Event);
 
    void OnLoop();
 
    void OnRender();
 
    void OnCleanup();
};

#endif
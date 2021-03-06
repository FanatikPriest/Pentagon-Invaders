#include <iostream>
#include <time.h>

#include "CApp.h"
#include "SpaceShip.h"
#include "Vector2f.h"
#include "WindowSettings.h"
 
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 1);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);

	sdlWindow = SDL_CreateWindow("Pentagon Invaders",
				SDL_WINDOWPOS_CENTERED ,
				SDL_WINDOWPOS_CENTERED,
				WindowSettings::WINDOW_WIDTH, WindowSettings::WINDOW_HEIGHT,
				SDL_WINDOW_OPENGL);
 
    if(sdlWindow == NULL) {
		std::cout << SDL_GetError() << std::endl;
        return false;
    }

	SDL_GL_CreateContext(sdlWindow);

	
	glViewport(0,0, WindowSettings::WINDOW_WIDTH, WindowSettings::WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WindowSettings::WINDOW_WIDTH, 0.0, WindowSettings::WINDOW_HEIGHT);

	srand((unsigned int)time(NULL));

    return true;
}
#include <iostream>

#include "CApp.h"
#include "SpaceShip.h"
#include "Vector2f.h"


const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
 
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
				WINDOW_WIDTH, WINDOW_HEIGHT,
				SDL_WINDOW_OPENGL);
 
    if(sdlWindow == NULL) {
		std::cout << SDL_GetError() << std::endl;
        return false;
    }

	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(sdlRenderer == NULL) {
		std::cout << SDL_GetError() << std::endl;
        return false;
    }

	Surf_Display = SDL_GetWindowSurface(sdlWindow);

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);

	glContext = SDL_GL_CreateContext(sdlWindow);

	
	glViewport(0,0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
	
	SpaceShip s(Vector2f(500.0f, 500.0f), 30);
	s.rotate(M_PI/9);
	Vector2f *vertices = s.getVertices();

	glBegin(GL_POLYGON);
		glColor3f(0.75f, 0.5f, 0.25f);


		for (int i = 0; i < s.getNumberOfVertices(); i++) {
			Vector2f v = vertices[i];

			glVertex2f(v.getX(), v.getY());
		}
	glEnd();

	glFlush();

	SDL_GL_SwapWindow(sdlWindow);

	SDL_RenderPresent(sdlRenderer);

    return true;
}
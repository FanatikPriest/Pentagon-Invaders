#include "CApp.h"
#include <iostream>

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
 
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

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

	glShadeModel(GL_SMOOTH);
	glViewport(0,0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);

	glBegin(GL_TRIANGLES); /* Drawing Using Triangles */
		glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex2f( 0.0f, 1.0f ); /* Top */
		glVertex2d(0, 0);

		glColor3f(0.0f, 1.0f, 0.0f);
		//glVertex2f( -1.0f, -1.0f ); /* Bottom Left */
		glVertex2d(100, 100);
		glColor3f(0.0f, 0.0f, 1.0f);
		//glVertex2f( 1.0f, -1.0f ); /* Bottom Right */
		glVertex2d(0, 100);
	glEnd(); /* Finished Drawing The Triangle */
	glFlush();

	SDL_GL_SwapWindow(sdlWindow);

	SDL_RenderPresent(sdlRenderer);
 
    return true;
}
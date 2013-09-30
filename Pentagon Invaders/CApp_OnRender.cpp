#include "CApp.h"
#include "DrawingUtils.h"

using namespace DrawingUtils;

void CApp::OnRender() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	renderShip(scene->getPlayerShip());
	renderShips(*scene->getShips());

	SDL_GL_SwapWindow(sdlWindow);
}
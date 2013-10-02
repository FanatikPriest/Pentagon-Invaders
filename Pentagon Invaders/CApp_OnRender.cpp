#include "CApp.h"
#include "DrawingUtils.h"

void CApp::OnRender() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawingUtils::renderBullets(*scene->getEnemyBullets());
	DrawingUtils::renderBullets(*scene->getPlayerBullets());

	DrawingUtils::renderShips(*scene->getShips());
	DrawingUtils::renderShip(scene->getPlayerShip());

	SDL_GL_SwapWindow(sdlWindow);
}
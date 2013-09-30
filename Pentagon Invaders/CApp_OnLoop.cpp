#include "CApp.h"
#include "MovementHandler.h"
 
void CApp::OnLoop() {
	SpaceShip& player = scene->getPlayerShip();

	MovementHandler::movePlayer(player);

	player.generateVertices();

	const std::list<SpaceShip*>& ships = *(scene->getShips());
	
	if (ships.size() <= 0)
	{
		// TODO create ships
	}
}
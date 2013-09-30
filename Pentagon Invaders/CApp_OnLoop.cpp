#include "CApp.h"
 
void CApp::OnLoop() {
	const std::list<SpaceShip*>& ships = *(scene->getShips());
	
	if (ships.size() <= 0)
	{
		// TODO create ships
	}
}
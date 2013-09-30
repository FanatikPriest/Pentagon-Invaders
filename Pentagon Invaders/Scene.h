#pragma once

#include <vector>

#include "SpaceShip.h"

class Scene
{
public:
	Scene();

	const SpaceShip& getPlayerShip() const;
	std::vector<SpaceShip*> getShips() const;
	void addSpaceShip(SpaceShip s);
private:

	

	void init();

	SpaceShip _playerShip;
	std::vector<SpaceShip*> _ships;
};
#pragma once

#include <list>

#include "SpaceShip.h"

class Scene
{
public:
	static Scene & getInstance();

	const SpaceShip& getPlayerShip() const;
	const std::list<SpaceShip*>* getShips() const;
	void addSpaceShip(SpaceShip s);
private:
	Scene() : _playerShip(SpaceShip(Vector2f(512.0f, 100.0f), 20, 3)) {};
	Scene(Scene const&);
	void operator=(Scene const&);

	SpaceShip _playerShip;
	std::list<SpaceShip*> _ships;
};
#include "Scene.h"

Scene::Scene() : _playerShip(Vector2f(512.0f, 650.0f), 20, 3) {}

const SpaceShip& Scene::getPlayerShip() const
{
	return _playerShip;
}

std::vector<SpaceShip*> Scene::getShips() const
{
	return _ships;
}

void Scene::addSpaceShip(SpaceShip s)
{
	_ships.push_back(&s);
}
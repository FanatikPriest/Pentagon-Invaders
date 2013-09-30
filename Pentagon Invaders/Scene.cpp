#include "Scene.h"

Scene & Scene::getInstance()
{
	static Scene * instance;

	if (instance == NULL) {
		instance = new Scene();
	}

	return *instance;
}

SpaceShip& Scene::getPlayerShip()
{
	return _playerShip;
}

std::list<SpaceShip*>* Scene::getShips()
{
	return &_ships;
}

void Scene::addSpaceShip(SpaceShip s)
{
	_ships.push_back(&s);
}
#include "Scene.h"

Scene & Scene::getInstance()
{
	static Scene * instance;

	if (instance == NULL) {
		instance = new Scene();
	}

	return *instance;
}

const SpaceShip& Scene::getPlayerShip() const
{
	return _playerShip;
}

const std::list<SpaceShip*>* Scene::getShips() const
{
	return &_ships;
}

void Scene::addSpaceShip(SpaceShip s)
{
	_ships.push_back(&s);
}
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

std::list<Bullet*>* Scene::getPlayerBullets()
{
	return &_playerBullets;
}

std::list<Bullet*>* Scene::getEnemyBullets()
{
	return &_enemyBullets;
}

void Scene::addSpaceShip(SpaceShip* s)
{
	_ships.push_back(s);
}

void Scene::addPlayerBullet(Bullet* b)
{
	_playerBullets.push_back(b);
}
void Scene::addEnemyBullet(Bullet* b)
{
	_enemyBullets.push_back(b);
}
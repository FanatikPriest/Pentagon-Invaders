#include "Scene.h"

Scene::Scene() : _playerShip(SpaceShip(Vector2f(512.0f, 100.0f), 20, 3))
{
	_playerShip.setColor(ColorManager::playerColor);
	_playerShip.setPlayer();
}

Scene::~Scene()
{
	// TODO delete all bullets and ships
}

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

void Scene::removeOffScreenObjects()
{
	removeOffScreenShips();
	removeOffScreenBullets(_playerBullets);
	removeOffScreenBullets(_enemyBullets);
}

void Scene::removeOffScreenShips()
{
	std::list<SpaceShip*>::iterator iter = _ships.begin();
	while (iter != _ships.end())
	{
		SpaceShip* ship = *iter;

		if (ship->isOffScreen())
		{
			_ships.erase(iter++);

			delete ship;
		}
		else 
		{
			++iter;
		}
	}
}

void Scene::removeOffScreenBullets(std::list<Bullet*>& bullets)
{
	std::list<Bullet*>::iterator iter = bullets.begin();
	while (iter != bullets.end())
	{
		Bullet* bullet = *iter;

		if (bullet->isOffScreen())
		{
			bullets.erase(iter++);

			delete bullet;
		}
		else 
		{
			++iter;
		}
	}
}
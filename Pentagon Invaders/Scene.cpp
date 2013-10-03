#include "Scene.h"

Scene::Scene() : _playerShip(SpaceShip(Vector2f(512.0f, 100.0f), 20, 3))
{
	_playerShip.setColor(ColorManager::playerColor);
	_playerShip.setStats(ShipStatistics());
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

std::vector<SpaceShip*>* Scene::getShips()
{
	return &_ships;
}

std::vector<Bullet*>* Scene::getPlayerBullets()
{
	return &_playerBullets;
}

std::vector<Bullet*>* Scene::getEnemyBullets()
{
	return &_enemyBullets;
}

void Scene::addSpaceShip(SpaceShip* s)
{
	_ships.push_back(s);
}

void Scene::addSpaceShips(std::vector<SpaceShip*>* ships)
{
	_ships.insert(_ships.end(), ships->begin(), ships->end());
}

void Scene::addPlayerBullet(Bullet* b)
{
	_playerBullets.push_back(b);
}
void Scene::addEnemyBullet(Bullet* b)
{
	_enemyBullets.push_back(b);
}

void Scene::removeUnusableObjects()
{
	removeUnusableShips();
	removeOffScreenBullets(_playerBullets);
	removeOffScreenBullets(_enemyBullets);
}

void Scene::removeUnusableShips()
{
	std::vector<SpaceShip*>::iterator iter = _ships.begin();
	while (iter != _ships.end())
	{
		SpaceShip* ship = *iter;

		if (ship->isOffScreen() || ship->getStats().isDead())
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

void Scene::removeOffScreenBullets(std::vector<Bullet*>& bullets)
{
	std::vector<Bullet*>::iterator iter = bullets.begin();

	while (iter != bullets.end())
	{
		Bullet* bullet = *iter;

		if (bullet->isOffScreen())
		{
			Bullet* bullet = *iter;
			//bullets.erase(iter++);

			//delete bullet;
		}
		else
		{
			++iter;
		}
	}
}
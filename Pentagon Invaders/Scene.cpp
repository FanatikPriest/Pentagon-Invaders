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
	_ships.erase(
		std::remove_if(_ships.begin(), _ships.end(), [](const SpaceShip* s)
			{
				return s->isOffScreen() || s->getStats().isDead();
			}
		),
		_ships.end()
	);
}

void Scene::removeOffScreenBullets(std::vector<Bullet*>& bullets)
{
	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(), 
			[](const Bullet * o) { return o->isOffScreen(); }),
		bullets.end()
	);
}
#pragma once

#include <list>

#include "SpaceShip.h"
#include "Bullet.h"
#include "ColorManager.h"

class Scene
{
public:
	static Scene & getInstance();

	SpaceShip& getPlayerShip();
	std::list<SpaceShip*>* getShips();
	std::list<Bullet*>* getPlayerBullets();
	std::list<Bullet*>* getEnemyBullets();
	void addSpaceShip(SpaceShip* s);
	void addPlayerBullet(Bullet* b);
	void addEnemyBullet(Bullet* b);
private:
	Scene() : _playerShip(SpaceShip(Vector2f(512.0f, 100.0f), 20, 3))
	{
		_playerShip.setColor(ColorManager::playerColor);
	}
	Scene(Scene const&);
	void operator=(Scene const&);

	SpaceShip _playerShip;
	std::list<SpaceShip*> _ships;
	std::list<Bullet*> _playerBullets;
	std::list<Bullet*> _enemyBullets;
};
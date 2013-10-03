#pragma once

#include <list>

#include "SpaceShip.h"
#include "Bullet.h"
#include "ColorManager.h"

class Scene
{
public:
	~Scene();

	static Scene & getInstance();

	SpaceShip& getPlayerShip();
	std::list<SpaceShip*>* getShips();
	std::list<Bullet*>* getPlayerBullets();
	std::list<Bullet*>* getEnemyBullets();
	void addSpaceShip(SpaceShip* s);
	void addSpaceShips(std::list<SpaceShip*>* ships);
	void addPlayerBullet(Bullet* b);
	void addEnemyBullet(Bullet* b);

	void removeUnusableObjects();
	
private:
	SpaceShip _playerShip;
	std::list<SpaceShip*> _ships;
	std::list<Bullet*> _playerBullets;
	std::list<Bullet*> _enemyBullets;

	Scene();
	Scene(Scene const&);
	void operator=(Scene const&);

	void removeUnusableShips();
	void removeOffScreenBullets(std::list<Bullet*>& bullets);
};
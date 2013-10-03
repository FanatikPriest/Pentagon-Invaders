#pragma once

#include <vector>
#include <algorithm>

#include "SpaceShip.h"
#include "Bullet.h"
#include "ColorManager.h"

class Scene
{
public:
	~Scene();

	static Scene & getInstance();

	SpaceShip& getPlayerShip();
	std::vector<SpaceShip*>* getShips();
	std::vector<Bullet*>* getPlayerBullets();
	std::vector<Bullet*>* getEnemyBullets();
	void addSpaceShip(SpaceShip* s);
	void addSpaceShips(std::vector<SpaceShip*>* ships);
	void addPlayerBullet(Bullet* b);
	void addEnemyBullet(Bullet* b);

	void removeUnusableObjects();
	
private:
	SpaceShip _playerShip;
	std::vector<SpaceShip*> _ships;
	std::vector<Bullet*> _playerBullets;
	std::vector<Bullet*> _enemyBullets;

	Scene();
	Scene(Scene const&);
	void operator=(Scene const&);

	void removeUnusableShips();
	void removeOffScreenBullets(std::vector<Bullet*>& bullets);
};
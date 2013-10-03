#pragma once

#include <SDL.h>
#include <cstdlib>
#include <time.h>

#include "SpaceShip.h"
#include "Bullet.h"
#include "Scene.h"
#include "ShipStatistics.h"


class BulletMaker
{
public:
	static const float DEFAULT_BULLET_RADIUS;

	BulletMaker();

	void makeBullets();

private:
	Uint32 _lastPlayerBullet;
	Uint32 _lastEnemyBullet;
	bool _isPlayerWaiting;
	bool _areEnemiesWaiting;
	Scene* _scene;

	void makePlayerBullets();
	void makeEnemyBullets();
};
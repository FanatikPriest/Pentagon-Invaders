#include "BulletMaker.h"

const float BulletMaker::DEFAULT_BULLET_RADIUS = 2.5f;

BulletMaker::BulletMaker()
{
	_lastPlayerBullet = SDL_GetTicks();
	_lastEnemyBullet = SDL_GetTicks();
	_isPlayerWaiting = false;
	_areEnemiesWaiting = false;
	_scene = &Scene::getInstance();
}

void BulletMaker::makeBullets()
{
	makePlayerBullets();
	makeEnemyBullets();
}

void BulletMaker::makePlayerBullets()
{
	SpaceShip& player = _scene->getPlayerShip();

	const Uint32 delay = player.getStats().getFireDelay();
	Uint32 now = SDL_GetTicks();

	if (_isPlayerWaiting)
	{
		if (now > _lastPlayerBullet + delay)
		{
			Vector2f* vertices = player.getVertices();
			Vector2f center = player.getCenter();
			float radius = DEFAULT_BULLET_RADIUS;
			float bulletSpeed = player.getStats().getBulletSpeed();
			int damage = player.getStats().getDamage();
			const Color& color = player.getColor();

			for (int i = 0; i < player.getNumberOfVertices(); i++)
			{
				Vector2f vertex = vertices[i];
				Vector2f direction = vertex - center;
				direction.normalize();

				Bullet* bullet = new Bullet(vertex, direction, radius, bulletSpeed, damage);
				bullet ->setColor(color);

				_scene->addPlayerBullet(bullet);
			}

			_isPlayerWaiting = false;
		}
	}
	else
	{
		_lastPlayerBullet = now;
		_isPlayerWaiting = true;
	}
}

void BulletMaker::makeEnemyBullets()
{
	std::vector<SpaceShip*>* ships = _scene->getShips();

	if (ships->empty())
	{
		return;
	}

	SpaceShip& firstShip = **ships->begin();

	const Uint32 delay = firstShip.getStats().getFireDelay();
	Uint32 now = SDL_GetTicks();

	if (_areEnemiesWaiting)
	{
		if (now > _lastEnemyBullet + delay)
		{
			for (auto iter = ships->begin(); iter != ships->end(); ++iter)
			{
				SpaceShip& enemy = **iter;
				
				int index = rand() % enemy.getNumberOfVertices();

				Vector2f vertex = enemy.getVertices()[index];
				Vector2f center = enemy.getCenter();
				Vector2f direction = vertex - center;
				direction.normalize();

				float radius = DEFAULT_BULLET_RADIUS;
				float bulletSpeed = enemy.getStats().getBulletSpeed();
				int damage = enemy.getStats().getDamage();

				const Color& color = enemy.getColor();

				Bullet* bullet = new Bullet(vertex, direction, radius, bulletSpeed, damage);
				bullet ->setColor(color);

				_scene->addEnemyBullet(bullet);
			}

			_areEnemiesWaiting = false;
		}
	}
	else
	{
		_lastEnemyBullet = now;
		_areEnemiesWaiting = true;
	}
}
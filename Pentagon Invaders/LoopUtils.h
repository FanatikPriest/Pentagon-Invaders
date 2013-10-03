#include <vector>

#include "SpaceShip.h"
#include "Bullet.h"

class LoopUtils
{
public:
	static void moveBullets(const std::vector<Bullet*>& bullets)
	{
		std::vector<Bullet*>::const_iterator iterator;
		for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
		{
			Bullet* bullet = *iterator;
			bullet->move();
		}
	}

	static bool interesects(const Vector2f center1, const float radius1, const Vector2f center2, const float radius2)
	{
		return (center2-center1).getMagnitude() < radius1 + radius2;
	}

	static void damageShips(std::vector<SpaceShip*>& ships, std::vector<Bullet*>& bullets)
	{
		if (ships.empty() || bullets.empty())
		{
			return;
		}

		auto iter = ships.begin();
		while (iter != ships.end())
		{
			SpaceShip* ship = *iter;

			damageShip(*ship, bullets);

			if (ship->getStats().isDead())
			{
				ships.erase(iter++);

				delete ship;
			}
			else
			{
				++iter;
			}
		}
	}

	static void damageShip(const SpaceShip& ship, std::vector<Bullet*>& bullets)
	{
		std::vector<Bullet*>::iterator bIter = bullets.begin();

		while (bIter != bullets.end())
		{
			Bullet* bullet = *bIter;

			if (interesects(ship.getCenter(), ship.getRadius(), bullet->getCenter(), bullet->getRadius()))
			{
				ship.getStats().inflictDamage(bullet->getDamage());

				Bullet* bullet = *bIter;
				bullets.erase(bIter++);

				//delete bullet;

				if (ship.getStats().isDead())
				{
					break;
				}
			}
			else
			{
				++bIter;
			}
		}
	}
};
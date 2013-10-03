#include <vector>

#include "SpaceShip.h"
#include "Bullet.h"

class LoopUtils
{
public:
	static void moveBullets(std::vector<Bullet*>& bullets)
	{
		std::vector<Bullet*>::iterator iterator;
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
		
		std::vector<SpaceShip*> toRemove;

		for (auto iter = ships.begin(); iter != ships.end(); ++iter)
		{
			SpaceShip* ship = *iter;

			damageShip(*ship, bullets);

			if (ship->getStats().isDead())
			{
				toRemove.push_back(ship);
			}
		}

		ships.erase(
			std::remove_if(ships.begin(), ships.end(), [toRemove](const SpaceShip * o)
				{
					return std::find(toRemove.begin(), toRemove.end(), o) != toRemove.end();
				}
			),
			ships.end()
		);
	}

	static void damageShip(const SpaceShip& ship, std::vector<Bullet*>& bullets)
	{
		std::vector<Bullet*> toRemove;

		std::vector<Bullet*>::iterator bIter;

		for (bIter = bullets.begin(); bIter != bullets.end(); ++bIter)
		{
			Bullet* bullet = *bIter;

			if (interesects(ship.getCenter(), ship.getRadius(), bullet->getCenter(), bullet->getRadius()))
			{
				ship.getStats().inflictDamage(bullet->getDamage());

				Bullet* bullet = *bIter;

				toRemove.push_back(bullet);

				if (ship.getStats().isDead())
				{
					break;
				}
			}
		}

		bullets.erase(
			std::remove_if(bullets.begin(), bullets.end(), [toRemove](const Bullet * o)
				{
					return std::find(toRemove.begin(), toRemove.end(), o) != toRemove.end();
				}
			),
			bullets.end()
		);
	}
};
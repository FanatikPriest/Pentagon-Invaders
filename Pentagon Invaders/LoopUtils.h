#include <list>

#include "SpaceShip.h"
#include "Bullet.h"

namespace LoopUtils
{
	void moveBullets(const std::list<Bullet*>& bullets)
	{
		std::list<Bullet*>::const_iterator iterator;
		for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
		{
			Bullet* bullet = *iterator;
			bullet->move();
		}
	}
}
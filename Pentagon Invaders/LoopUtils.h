#include <list>

#include "SpaceShip.h"
#include "Bullet.h"

class LoopUtils
{
public:
	static void moveBullets(const std::list<Bullet*>& bullets)
	{
		std::list<Bullet*>::const_iterator iterator;
		for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
		{
			Bullet* bullet = *iterator;
			bullet->move();
		}
	}
};
#include "ShipStatistics.h"

inline bool ShipStatistics::isDead() const
{
	return _health <= 0;
}

inline void ShipStatistics::inflictDamage(int damage)
{
	_health -= damage;
}

inline double ShipStatistics::getHealthPercentage() const
{
	return _health / _maxHealth;
}

inline int ShipStatistics::getHealth() const
{
	return _health;
}

inline int ShipStatistics::getDamage() const
{
	return _damage;
}
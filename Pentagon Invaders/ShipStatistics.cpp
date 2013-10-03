#include "ShipStatistics.h"

const float ShipStatistics::DEFAULT_BULLET_SPEED = 8.0f;

bool ShipStatistics::isDead() const
{
	return _health <= 0;
}

void ShipStatistics::inflictDamage(int damage)
{
	_health -= damage;
}

double ShipStatistics::getHealthPercentage() const
{
	return _health / _maxHealth;
}

int ShipStatistics::getHealth() const
{
	return _health;
}

int ShipStatistics::getDamage() const
{
	return _damage;
}

Uint32 ShipStatistics::getFireDelay() const
{
	return _fireDelay;
}

float ShipStatistics::getBulletSpeed() const
{
	return _bulletSpeed;
}
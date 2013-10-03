#pragma once

#include <SDL.h>

/**
	Represents the statistcs of a ship such as health, damage, etc.
 */
class ShipStatistics
{
public:
	ShipStatistics(int maxHealth = DEFAULT_MAX_HEALTH, int damage = DEFAULT_DAMAGE,
			Uint32 fireDelay = DEFAULT_FIRE_DELAY, float bulletSpeed = DEFAULT_BULLET_SPEED) : 
		_maxHealth(maxHealth),
		_health(maxHealth),
		_damage(damage),
		_fireDelay(fireDelay),
		_bulletSpeed(bulletSpeed)
	{}

	inline bool isDead() const;
	inline void inflictDamage(int damage);
	inline double getHealthPercentage() const;

	int getHealth() const;
	int getDamage() const;
	Uint32 getFireDelay() const;
	float getBulletSpeed() const;
private:
	static const int DEFAULT_MAX_HEALTH = 15;
	static const int DEFAULT_DAMAGE = 1;
	static const Uint32 DEFAULT_FIRE_DELAY = 250; // in milliseconds
	static const float DEFAULT_BULLET_SPEED;

	int _maxHealth;
	int _health;
	int _damage;
	Uint32 _fireDelay;
	float _bulletSpeed;
};
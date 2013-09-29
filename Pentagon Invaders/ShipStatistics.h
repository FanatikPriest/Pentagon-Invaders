#pragma once

/**
	Represents the statistcs of a ship such as health, damage, etc.
 */
class ShipStatistics
{
public:
	ShipStatistics(int maxHealth = DEFAULT_MAX_HEALTH, int damage = DEFAULT_DAMAGE) : 
		_maxHealth(maxHealth),
		_health(maxHealth),
		_damage(damage)
	{}

	inline bool isDead() const;
	inline void inflictDamage(int damage);
	inline double getHealthPercentage() const;

	inline int getHealth() const;
	inline int getDamage() const;
private:
	static const int DEFAULT_MAX_HEALTH = 100;
	static const int DEFAULT_DAMAGE = 1;

	int _maxHealth;
	int _health;
	int _damage;
};
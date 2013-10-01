#include "Bullet.h"

Bullet::Bullet(Vector2f center, Vector2f direction, float radius, float speed, int damage)
{
	_center = center;
	_direction = direction;
	_radius = radius;
	_speed = speed;
	_damage = damage;
}

void Bullet::move()
{
	_center = _center + (_direction * _speed * Delta::get());
}

const Vector2f& Bullet::getCenter() const
{
	return _center;
}
const float Bullet::getRadius() const
{
	return _radius;
}
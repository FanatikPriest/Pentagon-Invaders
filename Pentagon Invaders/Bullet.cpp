#include "Bullet.h"
#include "WindowSettings.h"

Bullet::Bullet(Vector2f center, Vector2f direction, float radius, float speed, int damage)
{
	_center = center;
	_direction = direction;
	_radius = radius;
	_speed = speed;
	_damage = damage;
	_color = &ColorManager::white;
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

const int Bullet::getDamage() const
{
	return _damage;
}

const Color& Bullet::getColor() const
{
	return *_color;
}

void Bullet::setColor(const Color& color)
{
	_color = &color;
}

const bool Bullet::isOffScreen() const
{
	float x = _center.getX();
	float y = _center.getY();

	bool left = x < -_radius;
	bool right = x > WindowSettings::WINDOW_WIDTH + _radius;
	bool bottom = y < -_radius;
	bool top = y > WindowSettings::WINDOW_HEIGHT + _radius;

	return left || right || bottom || top;
}

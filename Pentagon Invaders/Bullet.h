#pragma once

#include "Vector2f.h"
#include "Delta.h"

class Bullet
{
public:
	Bullet(Vector2f center, Vector2f direction, float radius, float speed, int damage);

	void move();

	const Vector2f& getCenter() const;
	const float getRadius() const;

	const bool isOffScreen() const;

private:
	Vector2f _center;
	Vector2f _direction;
	float _radius;
	float _speed;
	int	_damage;
};
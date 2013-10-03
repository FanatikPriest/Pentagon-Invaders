#pragma once

#include "Vector2f.h"
#include "Delta.h"
#include "Color.h"
#include "ColorManager.h"

class Bullet
{
public:
	Bullet(Vector2f center, Vector2f direction, float radius, float speed, int damage);

	void move();

	const Vector2f& getCenter() const;
	const float getRadius() const;
	const int getDamage() const;

	const Color& getColor() const;
	void setColor(const Color& color);

	const bool isOffScreen() const;

private:
	Vector2f _center;
	Vector2f _direction;
	float _radius;
	float _speed;
	int	_damage;
	const Color* _color;
};
#define _USE_MATH_DEFINES

#include <math.h>

#include "SpaceShip.h"
#include "Delta.h"
#include "WindowSettings.h"

#define PI2 (2 * M_PI)

SpaceShip::SpaceShip()
{
	_vertices = NULL;
	setColor(ColorManager::white);
}

SpaceShip::SpaceShip(const Vector2f center, float radius, int numberOfVertices)
{
	_numberOfVertices = numberOfVertices;
	_radius	= radius;
	_speed = 1.0f;
	_rotationSpeed = 1.0f;
	_rotationAngle = 0.0;
	_center = center;
	_vertices = NULL;
	_isPlayer = false;

	setColor(ColorManager::white);

	setStats(ShipStatistics());

	generateVertices();
}

SpaceShip::~SpaceShip()
{
	delete[] _vertices;
}

Vector2f SpaceShip::getCenter() const
{
	return _center;
}

inline void SpaceShip::generateVertices()
{
	if (_vertices != NULL)
	{
		delete[] _vertices;
	}

	_vertices = new Vector2f[_numberOfVertices];

	Vector2f radVect = Vector2f(0.0f, (float)_radius);

	for (int i = 0; i < _numberOfVertices; i++)
	{
		Vector2f direction = radVect.rotate((float) (PI2 * i / _numberOfVertices + _rotationAngle));
		_vertices[i] = _center + direction;
	}
}

void SpaceShip::move(const Vector2f& direction)
{
	_center = _center + (direction * _speed * Delta::get());

	if (_isPlayer)
	{
		float x = _center.getX();
		float y = _center.getY();

		if (x < _radius)
		{
			_center.setX((float)_radius);
		}
		else if (x > WindowSettings::WINDOW_WIDTH - _radius)
		{
			_center.setX((float)(WindowSettings::WINDOW_WIDTH - _radius));
		}

		if (y < _radius)
		{
			_center.setY((float)_radius);
		}
		else if (y > WindowSettings::WINDOW_HEIGHT - _radius)
		{
			_center.setY((float)(WindowSettings::WINDOW_HEIGHT - _radius));
		}
	}
}

void SpaceShip::rotate(double angle)
{
	_rotationAngle += angle * _rotationSpeed * Delta::get();

	bool recalculate = true;

	while (recalculate)
	{
		if (_rotationAngle > PI2)
		{
			_rotationAngle -= PI2;
		} 
		else if (_rotationAngle < 0.0)
		{
			_rotationAngle += PI2;
		}
		else
		{
			recalculate = false;
		}
	}
}

ShipStatistics SpaceShip::getStats() const
{
	return _stats;
}

void SpaceShip::setStats(const ShipStatistics stats)
{
	_stats = stats;
}

Vector2f* SpaceShip::getVertices() const
{
	Vector2f* clones = new Vector2f[_numberOfVertices];

	for (int i = 0; i < _numberOfVertices; i++)
	{
		clones[i] = _vertices[i];
	}

	return clones;
}

const int SpaceShip::getNumberOfVertices() const
{
	return _numberOfVertices;
}

const bool SpaceShip::isOffScreen() const
{
	float x = _center.getX();
	float y = _center.getY();

	bool left = x < -_radius;
	bool right = x > WindowSettings::WINDOW_WIDTH + _radius;
	bool bottom = y < -_radius;
	bool top = y > WindowSettings::WINDOW_HEIGHT + _radius;

	return left || right || bottom || top;
}

void SpaceShip::setColor(const Color& color)
{
	_color = &color;
}

const Color& SpaceShip::getColor() const
{
	return *_color;
}

void SpaceShip::setPlayer()
{
	_isPlayer = true;
}
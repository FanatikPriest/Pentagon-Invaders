#define _USE_MATH_DEFINES


#include "SpaceShip.h"
#include <math.h>

#define PI2 (2 * M_PI)

SpaceShip::SpaceShip(const Vector2f center, int radius, int numberOfVertices)
{
	_numberOfVertices = numberOfVertices;
	_radius = radius;
	_rotationAngle = 0;
	_center = center;
	generateVertices();
}

SpaceShip::~SpaceShip()
{
	delete[] _vertices;
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

void SpaceShip::rotate(double angle)
{
	_rotationAngle += angle;

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

	generateVertices();
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
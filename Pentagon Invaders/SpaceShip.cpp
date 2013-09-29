#define _USE_MATH_DEFINES

#include "SpaceShip.h"
#include <math.h>

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
		Vector2f direction = radVect.rotate((float) (2*M_PI * i / _numberOfVertices + _rotationAngle));
		_vertices[i] = _center + direction;
	}
}

inline void SpaceShip::rotate(double angle)
{
	//
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
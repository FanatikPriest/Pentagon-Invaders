#pragma once

#include "Vector2f.h"

/**
	Represents a space ship.
 */
class SpaceShip
{
public:
	static const int DEFAULT_RADIUS = 15;
	static const int DEFAULT_NUMBER_OF_VERTICES = 5;

	SpaceShip(const Vector2f center, int radius = DEFAULT_RADIUS, int numberOfVertices = DEFAULT_NUMBER_OF_VERTICES);
	~SpaceShip();

	void rotate(double angle);

	Vector2f* getVertices() const;
	const int getNumberOfVertices() const;

private:
	int _numberOfVertices;
	int _radius;
	double _rotationAngle;
	Vector2f _center;
	Vector2f* _vertices;
	
	void generateVertices();
};
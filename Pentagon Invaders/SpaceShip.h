#pragma once

#include "Vector2f.h"
#include "ShipStatistics.h"

/**
	Represents a space ship.
 */
class SpaceShip
{
public:
	SpaceShip();
	SpaceShip(const Vector2f center, int radius = DEFAULT_RADIUS, int numberOfVertices = DEFAULT_NUMBER_OF_VERTICES);
	~SpaceShip();

	void move(Vector2f& direction);
	void rotate(double angle);
	ShipStatistics getStats() const;
	void setStats(const ShipStatistics stats);

	Vector2f* getVertices() const;
	const int getNumberOfVertices() const;

	void generateVertices();

private:
	static const int DEFAULT_RADIUS = 15;
	static const int DEFAULT_NUMBER_OF_VERTICES = 5;

	int _numberOfVertices;
	int _radius;
	float _speed;
	float _rotationSpeed;
	double _rotationAngle;
	Vector2f _center;
	Vector2f* _vertices;
	ShipStatistics _stats;
};
#pragma once

#include "Vector2f.h"
#include "ShipStatistics.h"
#include "Color.h"
#include "ColorManager.h"

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

	void setColor(const Color& color);
	const Color& getColor() const;

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
	const Color* _color;
};
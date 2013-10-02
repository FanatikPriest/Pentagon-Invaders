#pragma once

#include <SDL.h>

#include "SpaceShip.h"
#include "KeyboardHandler.h"

class MovementHandler
{
public:
	static void movePlayer(SpaceShip& player);

private:
	static const float speed;
	static const float zero;

	static const float rotationSpeed;

	static const Vector2f up;
	static const Vector2f down;
	static const Vector2f left;
	static const Vector2f right;
};
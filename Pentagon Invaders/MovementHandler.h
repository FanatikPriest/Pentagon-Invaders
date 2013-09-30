#pragma once

#include <SDL.h>

#include "SpaceShip.h"
#include "KeyboardHandler.h"

namespace MovementHandler
{
	float speed = 5.0f;
	float zero = 0.0f;

	float rotationSpeed = 0.05f;

	Vector2f up(zero, speed);
	Vector2f down(zero, -speed);
	Vector2f left(-speed, zero);
	Vector2f right(speed, zero);

	void movePlayer(SpaceShip& player)
	{
		KeyboardHandler& keyboard = KeyboardHandler::getInstance();

		if (keyboard.w == SDL_PRESSED)
		{
			player.move(up);
		}

		if (keyboard.a == SDL_PRESSED)
		{
			player.move(left);
		}

		if (keyboard.s == SDL_PRESSED)
		{
			player.move(down);
		}

		if (keyboard.d == SDL_PRESSED)
		{
			player.move(right);
		}

		if (keyboard.left == SDL_PRESSED)
		{
			//rotate counter clockwise
			player.rotate((double)rotationSpeed);
		}

		if (keyboard.right == SDL_PRESSED)
		{
			//rotate clockwise
			player.rotate(-(double)rotationSpeed);
		}
	}
}

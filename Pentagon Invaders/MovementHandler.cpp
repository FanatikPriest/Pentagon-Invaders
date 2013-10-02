#include "MovementHandler.h"

const float MovementHandler::speed = 5.0f;
const float MovementHandler::zero = 0.0f;

const float MovementHandler::rotationSpeed = 0.06f;

const Vector2f MovementHandler::up = Vector2f(zero, speed);
const Vector2f MovementHandler::down = Vector2f(zero, -speed);
const Vector2f MovementHandler::left = Vector2f(-speed, zero);
const Vector2f MovementHandler::right = Vector2f(speed, zero);

void MovementHandler::movePlayer(SpaceShip& player)
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
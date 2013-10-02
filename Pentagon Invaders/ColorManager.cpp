#include "ColorManager.h"

const Color ColorManager::palette [5] = {
	Color(0.392f, 0.047f, 0.671f), // purple
	Color(0.788f, 0.0f, 0.478f), // violet
	Color(1.0f, 0.0f, 0.0f), // red
	Color(1.0f, 0.514f, 0.0f), // orange
	Color(1.0f, 0.855f, 0.0f) // yellow
};

const Color ColorManager::playerColor = Color(0.42f, 0.894f, 0.0f); // green

const Color ColorManager::black = Color(0.0f, 0.0f, 0.0f);
const Color ColorManager::white = Color(1.0f, 1.0f, 1.0f);

Color ColorManager::lastColor = black;

const Color& ColorManager::getRandom()
{
	srand((unsigned int)time(NULL));
	const Color& color = palette[rand() % 5];

	if (color == lastColor)
	{
		return getRandom();
	}

	return color;
}
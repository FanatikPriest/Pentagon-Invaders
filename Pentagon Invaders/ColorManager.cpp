#include "ColorManager.h"

const Color& ColorManager::getRandom()
{
	return palette[rand() % 5];
}
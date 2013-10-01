#include "Delta.h"

Delta::Delta()
{
	_last = SDL_GetTicks();
	_delta = 0.0f;
}

float Delta::get()
{
	return getInstance()._delta;
}

void Delta::set()
{
	Delta& d = getInstance();
	Uint32 now = SDL_GetTicks();
		
	d._delta = (now - d._last) / 25.0f;
	d._last = now;
}

Delta& Delta::getInstance()
{
	static Delta* instance;

	if (instance == NULL)
	{
		instance = new Delta();
	}

	return *instance;
}
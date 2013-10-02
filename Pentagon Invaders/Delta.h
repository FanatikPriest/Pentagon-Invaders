#pragma once

#include <SDL.h>

class Delta
{
public:
	static float get();
	static void set();

private:
	static Uint32 _last;
	static float _delta;

	Delta();
	Delta(Delta&);
	void operator=(const Delta&);
};
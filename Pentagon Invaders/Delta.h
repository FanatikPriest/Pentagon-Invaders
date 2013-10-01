#pragma once

#include <SDL.h>

class Delta
{
public:
	static float get();
	static void set();

private:
	Uint32 _last;
	float _delta;

	static Delta& getInstance();

	Delta();
	Delta(Delta&);
	void operator=(const Delta&);

};
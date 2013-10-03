#pragma once

#include <SDL.h>

#include "SpaceShip.h"
#include "Scene.h"
#include "WindowSettings.h"
#include "ColorManager.h"

class WaveMaker
{
public:
	WaveMaker();

	bool isWaveOver();
	void startWave();

private:
	static const Uint32 WAVE_DELAY_TIME;

	Uint32 _lastPush;
	Scene* _scene;
	bool _isWaiting;

	void makeWave();
	void generateEnemies();
};
#include "WaveMaker.h"

const Uint32 WaveMaker::WAVE_DELAY_TIME = 5000; // 5 seconds delay

WaveMaker::WaveMaker()
{
	_scene = &Scene::getInstance();
	_lastPush = SDL_GetTicks();
	_isWaiting = false;
}

bool WaveMaker::isWaveOver()
{
	return _scene->getShips()->empty();
}

void WaveMaker::startWave()
{
	if (isWaveOver())
	{
		if (_isWaiting)
		{
			Uint32 now = SDL_GetTicks();

			if (now > _lastPush + WAVE_DELAY_TIME)
			{
				makeWave();
				_isWaiting = false;
			}
		}
		else 
		{
			_lastPush = SDL_GetTicks();
			_isWaiting = true;
		}
	}
}

void WaveMaker::makeWave()
{
	generateEnemies();
	// TODO anything else?
}

void WaveMaker::generateEnemies()
{
	int count = 3;
	float widthStep = (float) (WindowSettings::WINDOW_WIDTH / (count + 1));
	float radius = 30.0f;
	const Color& color = ColorManager::getRandom();
	ShipStatistics stats;

	for (int i = 0; i < count; i++)
	{
		Vector2f position((i+1) * widthStep, WindowSettings::WINDOW_HEIGHT - 100.0f);

		SpaceShip* ship = new SpaceShip(position, radius);
		ship->setColor(color);
		ship->setStats(stats);

		_scene->addSpaceShip(ship);
	}
}
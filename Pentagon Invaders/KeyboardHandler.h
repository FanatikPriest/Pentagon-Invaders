#pragma once

#include <SDL.h>

class KeyboardHandler
{
public:
	static KeyboardHandler& getInstance() {
		static KeyboardHandler* instance;

		if (instance == NULL) 
		{
			instance = new KeyboardHandler();
		}

		return *instance;
	}

	Uint8 w, a, s, d, left, right;
	
private:
	KeyboardHandler()
	{
		w = a = s = d = left = right = SDL_RELEASED;
	}

	KeyboardHandler(KeyboardHandler&);
	void operator=(KeyboardHandler const&);
};
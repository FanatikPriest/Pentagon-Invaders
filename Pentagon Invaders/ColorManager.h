#pragma once

#include <cstdlib>
#include <time.h>

#include "Color.h"

class ColorManager
{
public:
	static const Color palette [5];

	static const Color playerColor;

	static const Color black;
	static const Color white;

	static const Color& getRandom();
private:
	static const Color* _lastColor;
};
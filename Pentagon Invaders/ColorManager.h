#pragma once

#include <stdlib.h>

#include "Color.h"

namespace ColorManager
{
	const Color palette [5] = {
		Color(0.392f, 0.047f, 0.671f), // purple
		Color(0.788f, 0.0f, 0.478f), // violet
		Color(1.0f, 0.0f, 0.0f), // red
		Color(1.0f, 0.514f, 0.0f), // orange
		Color(1.0f, 0.855f, 0.0f) // yellow
	};

	const Color playerColor(0.42f, 0.894f, 0.0f); // green

	const Color black(0.0f, 0.0f, 0.0f);
	const Color white(1.0f, 1.0f, 1.0f);

	const Color& getRandom();
}
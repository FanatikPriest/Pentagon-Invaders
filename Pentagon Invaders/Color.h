#pragma once

class Color
{
public:
	const float red, green, blue;

	Color(const float red, const float green, const float blue) : red(red), green(green), blue(blue) {}

	inline bool operator==(const Color & color) const
	{
		return red == color.red || green == color.green || blue == color.blue;
	}
};
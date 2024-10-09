#pragma once

#include <cmath>

enum class PointType
{
	cartensian,
	polar
};

class CPoint
{
public:
	CPoint(float _x, float _y) : x(_x), y(_y) { }
	CPoint(float _x, float _y, PointType type = PointType::cartensian)
	{
		if (type == PointType::cartensian)
		{
			x = _x;
			y = _y;
		}
		else if (type == PointType::polar)
		{
			x = _x * std::cos(_y);
			y = _x * std::sin(_y);
		}
		else
		{
			x = 0.0f; 
			y = 0.0f;
		}
	}

private:
	float x;
	float y;
};


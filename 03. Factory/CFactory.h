#pragma once

#include <cmath>

class CPoint2
{
private:
	CPoint2(float _x, float _y) : x(_x), y(_y) { }

public:
	float x;
	float y;
	friend class CFactory;
};

class CFactory
{

public:
	static CPoint2 NewCartesian(float x, float y)
	{
		return CPoint2{ x,y };
	}

	static CPoint2 NewPolar(float r, float theta)
	{
		return CPoint2{ r * std::cos(theta), r * std::sin(theta) };
	}

};


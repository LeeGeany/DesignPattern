
#include <cmath>

class CPoint1
{
protected:
	CPoint1(float _x, float _y) : x(_x), y(_y) { }

public:
	static CPoint1 NewCartesian(float x, float y)
	{
		return { x,y };
	}

	static CPoint1 NewPolar(float r, float theta)
	{
		return { r * std::cos(theta), r * std::sin(theta) };
	}

private:
	float x;
	float y;
};
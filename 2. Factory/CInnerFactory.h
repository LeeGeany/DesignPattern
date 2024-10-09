#include <cmath>

class CPoint3
{
private:
	CPoint3(float _x, float _y) : x(_x), y(_y) { }

	class CFactory
	{
	private:
		CFactory();
	
	public:
		static CPoint3 NewCartesian(float x, float y)
		{
			return { x,y };
		}

		static CPoint3 NewPolar(float r, float theta)
		{
			return { r * std::cos(theta), r * std::sin(theta) };
		}
	};

public:
	float x;
	float y;
	static CFactory factory;
};
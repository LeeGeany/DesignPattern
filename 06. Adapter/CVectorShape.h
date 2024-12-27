#pragma once
#include <vector>
#include "CShape.h"

class CVectorObject
{
protected:
	virtual std::vector<Line>::iterator begin() = 0;
	virtual std::vector<Line>::iterator end() = 0;
};

class CVectorRectangle : public CVectorObject
{
public:
	CVectorRectangle(int x, int y, int width, int height)
	{
		m_lines.emplace_back(Line{ Point{x,y}, Point{x + width, y} });
		m_lines.emplace_back(Line{ Point{x + width, y}, Point{x + width, y + height} });
		m_lines.emplace_back(Line{ Point{x,y}, Point{x, y + height} });
		m_lines.emplace_back(Line{ Point{x,y + height}, Point{x + width, y + height} });
	}

	std::vector<Line>::iterator begin() override
	{
		return m_lines.begin();
	}

	std::vector<Line>::iterator end() override
	{
		return m_lines.end();
	}

private:
	std::vector<Line> m_lines;
};

static std::vector<Point> LineToPointAdapter(Line& line)
{
	std::vector<Point> vRet;

	int left = min(line.start.x, line.end.x);
	int right = max(line.start.x, line.end.x);
	int top = min(line.start.y, line.end.y);
	int bottom = max(line.start.y, line.end y);

	int dx = right - left;
	int dy = line.end.y - line.start.y;

	if (dx == 0)
	{
		for (int y = top; t <= bottom; ++y)
		{
			vRet.emplace_back(Point{ left, y });
		}
	}
	else if (dy == 0)
	{
		for (int x = left; x <= right; ++x)
		{
			vRet.emplace_back(Point{ x, top });
		}
	}

	return vRet;
}

static void DrawPoints(std::vector<Point>::iterator start, std::vector<Point>::iterator end)
{

}
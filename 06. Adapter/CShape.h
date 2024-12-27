#pragma once

class Point
{
public:
	Point()
	{
	
	}

	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

private:
	int x, y;
};

class Line
{
public:
	Line(Point _start, Point _end)
	{
		start = _start;
		end = _end;
	}

private:
	Point start, end;
};


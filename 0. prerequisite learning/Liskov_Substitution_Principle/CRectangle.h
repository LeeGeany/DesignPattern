#pragma once
class CRectangle
{
protected:
	int width, height;

public:
	CRectangle(const int _width, const int _height)
	: width{ _width }, height{ _height }
	{
		
	}

	int getWidth() { return width; }
	int getHeight() { return height; }
	virtual void setWidth(const int _width) { this->width = _width; }
	virtual void setHeight(const int _height) { this->height = _height; }

	int area() { return width * height; }
};

class cSquare : public CRectangle
{
public:
	cSquare(const int size) : CRectangle(size, size) {}

	virtual void setWidth(const int _width) { this->width = height = _width; }
	virtual void setHeight(const int _height) { this->height = width = _height; }
};


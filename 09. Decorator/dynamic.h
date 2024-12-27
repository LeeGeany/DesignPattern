#pragma once

#include <sstream>
#include <string>

class Shape
{
public:
	virtual std::string str() const = 0;
};

class Circle : public Shape
{
private:
	float radius;

public:
	explicit Circle(const float radius) : radius(radius) {}

	void resize(float factor) { radius *= factor; }

	virtual std::string str() const override
	{
		std::ostringstream oss;
		oss << "A circle of radius " << radius;
		return oss.str();
	}
};

class MakeColor : public Shape
{
private:
	Shape& shape;
	std::string color;

public:
	MakeColor(Shape& shape, const std::string color)
		: shape(shape), color(color) {
	}

	virtual ~MakeColor() {}

public:
	std::string str() const override
	{
		std::ostringstream oss;
		oss << shape.str() << " has the color " << color;
		return oss.str();
	}

};

class MakeTransparent : public Shape
{
private:
	Shape& shape;
	uint8_t transparency;

public:
	MakeTransparent(Shape& shape, uint8_t transparency) 
	: shape(shape), transparency(transparency) { }

	std::string str() const override
	{
		std::ostringstream oss;
		oss << shape.str() << " has the transparency " << static_cast<int>(transparency);
		return oss.str();
	}
};
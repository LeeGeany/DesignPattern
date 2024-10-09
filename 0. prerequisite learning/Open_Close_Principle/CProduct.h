#pragma once

#include <string>

enum class Color	{ Red, Green, Blue };
enum class Size		{ Small, Medium, Large };

class CProduct
{
public:
	std::string name;
	Color color;
	Size size;
};




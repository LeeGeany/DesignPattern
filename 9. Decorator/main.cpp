#include <iostream>
#include "dynamic.h"
#include "static.h"
#include  "function.h"

int main(void)
{
	//Circle circle(3.14);

	//MakeColor colorcircle(circle, "yellow");
	//std::cout << colorcircle.str() << std::endl;

	//MakeTransparent transparencycircle(circle, 124);
	//std::cout << transparencycircle.str() << std::endl;

	//MakeTransparent doublecircle(colorcircle, 128);
	//std::cout << doublecircle.str() << 9860std::endl;

	//mixInMakeColor<Circle> mixincircle("blue");

	auto func1 = []() { std::cout << "hello" << std::endl; };
	Logger(func1, "Hello Function");

	return 0;
}
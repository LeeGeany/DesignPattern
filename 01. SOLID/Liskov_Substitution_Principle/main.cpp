#include <iostream>

#include "CRectangle.h"
#include "FactoryRectangle.h"

void Process(CRectangle& r)
{
	int w = r.getWidth();
	r.setHeight(10);

	std::cout << "Expected area = " << r.area() << "\n";
}

int main(void)
{
	CRectangle r(20, 20);
	cSquare s(20);

	Process(r);
	Process(s);

	CRectangle* r1 = CFactoryRectangle::Create_Rectangle(20, 20);
	CRectangle* s1 = CFactoryRectangle::Create_Square(20);

	Process(*r1);
	Process(*s1);

	return 0;
}
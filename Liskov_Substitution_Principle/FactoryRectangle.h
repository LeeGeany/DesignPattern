#pragma once

#include "CRectangle.h"

class CFactoryRectangle
{
public:
	static CRectangle* Create_Rectangle(int w, int h)
	{
		return new CRectangle(w, h);
	}

	static CRectangle* Create_Square(int size)
	{
		return new CRectangle(size, size);
	}
};
#include "CInnerFactory.h"
#include "CFactory.h"
#include "CFactoryMethod.h"
#include "CPoint.h"

int main(void)
{
	CPoint	p0 = CPoint(3, 2, PointType::cartensian);
	CPoint1 p1 = CPoint1::NewPolar(3, 1.24);
	CPoint2 p2 = CFactory::NewPolar(3, 1.24);
	CPoint3 p3 = CPoint3::factory.NewCartesian(3, 2);
	return 0;
}
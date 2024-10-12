#pragma once

#include "IScan.h"
#include "IFax.h"
#include "IPrint.h"

/*
class IPrinter
{
public:
	IPrinter() {}
	virtual ~IPrinter() {}

private:
	virtual void Fax() = 0;
	virtual void Scan() = 0;
	virtual void Print() = 0;
};
*/

class IPrinter : public IScan, public IFax, public IPrint
{
public:
	IPrinter() {};
	virtual ~IPrinter() {}
};

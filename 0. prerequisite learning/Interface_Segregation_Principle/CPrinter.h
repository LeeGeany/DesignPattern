#pragma once

#include "IPrinter.h"

class CPrinter : public IPrinter
{
public:
	CPrinter() {};
	virtual ~CPrinter() {};

public:
	/*
	virtual void Fax() override;
	virtual void Scan() override;
	virtual void Print() override;
	*/

	virtual void OnFax() override;
	virtual void OnScan() override;
	virtual void OnPrint() override;
};


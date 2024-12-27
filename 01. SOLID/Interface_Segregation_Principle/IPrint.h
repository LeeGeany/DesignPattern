#pragma once

class IPrint
{
public:
	IPrint() {};
	virtual ~IPrint() {};

protected:
	virtual void OnPrint() = 0;
};
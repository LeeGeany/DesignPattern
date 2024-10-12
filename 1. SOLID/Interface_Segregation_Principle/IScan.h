#pragma once

class IScan
{
public:
	IScan() {};
	virtual ~IScan() {};

protected:
	virtual void OnScan() = 0;
};
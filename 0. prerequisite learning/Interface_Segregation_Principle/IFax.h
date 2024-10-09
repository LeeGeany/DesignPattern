#pragma once

class IFax
{
public:
	IFax() {};
	virtual ~IFax() {};

protected:
	virtual void OnFax() = 0;
};
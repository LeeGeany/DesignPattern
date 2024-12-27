#pragma once

#include <iostream>

class ILog
{
public:
	ILog() {}
	virtual ~ILog() {}

private:
	virtual	void Log(const char* const str) = 0;
};


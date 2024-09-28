#pragma once

#include "ILog.h"
#include "IEngine.h"

class CCar : public ILog, public IEngine
{
public:
	CCar() {}
	virtual ~CCar() {}

public:
	virtual	void Log(const char* const str) override;
	virtual	void Run() override;
};


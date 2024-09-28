#pragma once
class IEngine
{
public:
	IEngine() {}
	virtual ~IEngine() {}

private:
	virtual	void Run()=0;
};


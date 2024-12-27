#pragma once
#include <iostream>
#include <functional>
#include <string>

class Logger
{
private:
	std::function<void()> func;
	std::string name;

public:
	Logger(/*const std::function<void()> func, const std::string& name*/)
	//: func(func), name(name) 
	{ }

	void operator()(const std::function<void()> func, const std::string& name) const
	{
		std::cout << "Entering " << name << std::endl;
		func();
		std::cout << "Exiting " << name << std::endl;
	}
};
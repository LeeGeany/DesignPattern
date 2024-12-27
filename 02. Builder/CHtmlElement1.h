#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "CHtmlBuilder.h"

class CHtmlElement1
{
public:
	std::string name;
	std::string text;
	std::vector<CHtmlElement> element;

	static std::unique_ptr<CHtmlBuilder> build(const std::string& root_name)
	{
		return std::make_unique<CHtmlBuilder>(root_name);
	}

protected:
	CHtmlElement1() {}
	CHtmlElement1(const std::string& name, const std::string& text)
		:name(name), text(text)
	{

	}

	virtual ~CHtmlElement1() {}

	void str(int indent = 0) const
	{
		std::cout << name << '\n';
		for (auto list : element)
		{
			std::cout << "  " << list.name << list.text << list.name << "\n";
		}
		std::cout << name << '\n';
	}
};


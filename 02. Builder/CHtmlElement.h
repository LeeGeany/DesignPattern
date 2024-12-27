#pragma once

#include <iostream>
#include <string>
#include <vector>

class CHtmlElement
{
public:
	std::string name;
	std::string text;
	std::vector<CHtmlElement> element;

public:
	CHtmlElement() {}
	CHtmlElement(const std::string& name, const std::string& text)
	:name(name), text(text)
	{
	
	}

	virtual ~CHtmlElement() {}

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


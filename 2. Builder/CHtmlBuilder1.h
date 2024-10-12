#pragma once

#include "CHtmlElement.h"

class CHtmlBuilder1
{
private:
	CHtmlElement root;

public:
	CHtmlBuilder1(std::string root_name) { root.name = root_name; }
	virtual ~CHtmlBuilder1() {}

	CHtmlBuilder1& add_child(std::string child_name, std::string child_text)
	{
		CHtmlElement e{ child_name, child_text };
		root.element.emplace_back(e);
		return *this;
	}

	void str()
	{
		root.str();
	}
};
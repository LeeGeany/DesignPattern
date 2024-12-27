#pragma once

#include "CHtmlElement.h"

class CHtmlBuilder
{
private:
	CHtmlElement root;

public:
	CHtmlBuilder(std::string root_name) { root.name = root_name; }
	virtual ~CHtmlBuilder() {}

	void add_child(std::string child_name, std::string child_text)
	{
		CHtmlElement e{ child_name, child_text };
		root.element.emplace_back(e);
	}

	void str()
	{
		root.str();
	}
};
#pragma once

#include <iostream>
#include <string>
#include <vector>

class CTag
{
private:
	std::string name;
	std::string text;
	std::vector<CTag> children;
	std::vector<std::pair<std::string, std::string>> attributes;

public:
	friend std::ostream& operator<<(std::ostream& os, const CTag& tag)
	{
	
	}

protected:
	CTag(const std::string& name, const std::string& text)
	: name(name), text(text)
	{
		
	}

	CTag(const std::string& name, const std::vector<CTag>& children)
: name(name), children(children)
	{

	}
};
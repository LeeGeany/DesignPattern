#pragma once

#include <string>

#include "CTag.h"

class P : public CTag
{
public:
	explicit P(const std::string& text)
	: CTag{ "P", text } {}

	P(std::initializer_list<CTag> children)
	: CTag("P", children) {}
};
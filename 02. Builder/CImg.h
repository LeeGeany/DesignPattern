#pragma once

#include "CTag.h"

class CImg : public CTag
{
public:
	explicit CImg(const std::string text)
	: CTag("Img", text) {}

	CImg(std::vector<CTag> children)
	: CTag("Img", children) {}
};
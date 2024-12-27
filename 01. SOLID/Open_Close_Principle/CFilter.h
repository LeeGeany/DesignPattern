#pragma once

#include <vector>

#include "CProduct.h"
#include "CSpecification.h"

/*
class CBasicFilterekdma
{
public:
	static std::vector<CProduct*> by_color(std::vector<CProduct*> items, Color color)
	{
		std::vector<CProduct*> result;
		for (auto& p : items)
		{
			if (p->color == color)
			{
				result.push_back(p);
			}
		}
		return result;
	}
};
*/

template <typename T> class CFilter
{
public:
	virtual std::vector<T*> filter(std::vector<T*> items, CSpecification<T>& spec) = 0;
};

class CBetterFilter : public CFilter<CProduct>
{
public:
	virtual std::vector<CProduct*> filter(std::vector<CProduct*> items, CSpecification<CProduct>& spec) override
	{
		std::vector<CProduct*> result;
		for (auto& p : items)
		{
			if (spec.is_satisfied(p))
			{
				result.push_back(p);
			}
		}
		return result;
	}
};

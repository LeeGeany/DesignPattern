#pragma once

#include "CProduct.h"

template <typename T> class CSpecification
{
public:
	virtual bool is_satisfied(T* item) = 0;
};

class ColorSpecification : public CSpecification<CProduct>
{
	Color color;

public:
	explicit ColorSpecification(const Color color) : color{ color } {}

	virtual bool is_satisfied(CProduct* item) override
	{
		return item->color == color;
	}
};

class SizeSpecification : public CSpecification<CProduct>
{
	Size size;

public:
	explicit SizeSpecification(const Size size) : size{ size } {}

	virtual bool is_satisfied(CProduct* item) override
	{
		return item->size == size;
	}

};

template <typename T> class AndSpecification : public CSpecification<T>
{
	CSpecification<T>& first;
	CSpecification<T>& second;

public:
	AndSpecification(CSpecification<T>& first, CSpecification<T>& second) : first{first}, second{second}
	{

	}

	virtual bool is_satisfied(CProduct* item) override
	{
		return first.is_satisfied(item) && second.is_satisfied(item);
	}

};
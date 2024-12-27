#pragma once
#include "dynamic.h"

template <typename T> class mixInMakeColor : T
{
	static_assert(std::is_base_of<Shape, T>::value, "Template argument must be a Shape!");
private:
	std::string color;

public:
	std::string str() const override
	{
		std::ostringstream oss;
		oss << T::str() << " has the color " << color;
		return oss.str();
	}
};

// 생성자를 한번에 편리하게 호출하던 부분 구현

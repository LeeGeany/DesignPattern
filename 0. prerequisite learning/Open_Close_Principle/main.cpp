#include <iostream>
#include <vector>

#include "CProduct.h"
#include "CFilter.h"

int main(void)
{
	CProduct product1{ "Apple", Color::Red, Size::Small };
	CProduct product2{ "Tree", Color::Green, Size::Large };
	CProduct product3{ "House", Color::Blue, Size::Medium };

	std::vector<CProduct*> All{ &product1, &product2, &product3 };
/*
	auto basic_result = CBasicFilter::by_color(All, Color::Green);

	for (auto item : Green_Result)
	{
		std::cout << item->name << "\n";
	}
*/
	CBetterFilter BF;
	ColorSpecification Green(Color::Green);
	SizeSpecification Medium(Size::Medium);
	AndSpecification<CProduct> And(Green, Medium);

	auto Green_Result = BF.filter(All, Green);
	auto Medium_Result = BF.filter(All, Medium);
	auto And_Result = BF.filter(All, And);

	for (auto item : Green_Result)
	{
		std::cout << item->name << "\n";
	}

	for (auto item : Medium_Result)
	{
		std::cout << item->name << "\n";
	}

	for (auto item : And_Result)
	{
		std::cout << item->name << "\n";
	}

	return 0;
}
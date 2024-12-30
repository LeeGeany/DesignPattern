#include <iostream>

#include "strategy.h"

int main(void)
{
	TextProcessor tp;
	tp.set_output_format(OutputFormat::MARKDONW);
	tp.append_list({ "hello", "world","good" });
	std::cout << tp.str() << std::endl;

	TextProcessor_2<HTMLListStrategy> tp2;
	tp2.append_list({ "hello", "world","good" });
	std::cout << tp2.str() << std::endl;
}
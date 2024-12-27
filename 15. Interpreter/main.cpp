#include "Lexing.h"
#include "Parsing.h"

int main(void)
{
	std::string input = "(13-4)-(12_1)";
	std::vector<Token> tokens = lex_2(input);

	auto parsed = parse(tokens);
	std::cout << parsed->eval();

	return 0;
}
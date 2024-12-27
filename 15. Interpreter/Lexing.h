#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Token
{
public:
	enum Type {integer, plus, minus, lparen, rparen} type;
	std::string text;

	explicit Token(Type type, const std::string text)
	: type{ type }, text{ text }
	{
	}

	friend std::ostream operator<<(std::ostream& os, const Token& obj)
	{
		//return os << "`" << obj.text << "`";
	}
};

std::vector<Token> lex_2(std::string& input)
{
	std::vector<Token> result;

	for (int i = 0; i < input.size(); ++i)
	{
		switch (input[i])
		{
		case '+':
			result.push_back(Token{ Token::plus, "+" });
			break;
		case '-':
			result.push_back(Token{ Token::minus, "-" });
			break;
		case '(':
			result.push_back(Token{ Token::lparen, "(" });
			break;
		case ')':
			result.push_back(Token{ Token::rparen, ")" });
			break;
		default :
			std::ostringstream buffer;
			buffer << input[i];
			for (int j = i + 1; j < input.size(); ++j)
			{
				if (isdigit(input[j]))
				{
					buffer << input[j];
					++i;
				}
				else
				{
					result.push_back({ Token{Token::integer, buffer.str()} });
					break;
				}
			}
			break;
		}
	}

	return result;
}
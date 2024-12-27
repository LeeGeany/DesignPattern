#pragma once
#include <memory>
#include <vector>

#include <boost/lexical_cast.hpp>

#include "Lexing.h"

class Element
{
public:
	virtual int eval() const = 0;
};

class Integer : public Element
{
public:
	int value;

	explicit Integer(const int value)
	: value(value) {}

	int eval() const override { return value; }
};

class BinaryOperation : public Element
{
public:
	enum Type {addition, subtraction} type;
	std::shared_ptr<Element> lhs, rhs;

	int eval() const override
	{
		if (type == addition)
		{
			return lhs->eval() + rhs->eval();
		}
		return lhs->eval() - rhs->eval();
	}
};

std::shared_ptr<Element> parse(std::vector<Token>& tokens)
{
	auto result = std::make_unique<BinaryOperation>();
	bool have_lhs = false;

	for (size_t i = 0; i < tokens.size(); i++)
	{
		Token token = tokens[i];
		switch (token.type)
		{
		case Token::integer:
		{
			int value = boost::lexical_cast<int>(token.text);
			auto integer = std::make_shared<Integer>(value);
			if (!have_lhs)
			{
				result->lhs = integer;
				have_lhs = true;
			}
			else
			{
				result->rhs = integer;
			}
			break;
		}
		case Token::plus:
		{
			result->type = BinaryOperation::addition;
			break;
		}
		case Token::minus:
		{
			result->type = BinaryOperation::subtraction;
			break;
		}
		case Token::lparen:
		{
			int j = i;
			for (; j < tokens.size(); ++j)
			{
				if (tokens[j].type == Token::rparen)
					break;

				std::vector<Token> subexpression(&tokens[i + 1], &tokens[j]);
				auto element = parse(subexpression);

				if (!have_lhs)
				{
					result->lhs = element;
					have_lhs = true;
				}
				else
				{
					result->rhs = element;
				}
				i = j;
			}
			break;
		}
		}
	}
	return result;
}
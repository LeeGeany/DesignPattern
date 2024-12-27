#pragma once

#include "CPerson.h"
#include "CPersonBuilderBase.h"

class CPersonJobBuilder : public CPersonBuilderBase 
{
	typedef CPersonJobBuilder Self;

public:
	explicit CPersonJobBuilder(CPerson& person)
	: CPersonBuilderBase( person ) {}

	Self& at(std::string company_name) {
		person.company_name = company_name;
		return *this;
	}

	Self& as_a(std::string position) {
		person.position = position;
		return *this;
	}

	Self& earning(int annual_income) {
		person.annual_income = annual_income;
		return *this;
	}
};
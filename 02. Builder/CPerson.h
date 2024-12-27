#pragma once

#include <iostream>
#include<sstream>
#include <string>

#include "CPersonBuilder.h"

class CPersonJobBuilder;
class cPersonAddressBuilder;

class CPerson 
{
public:
	CPerson() {}
	virtual ~CPerson() {}

private:
	std::string street_address;
	std::string post_code;
	std::string city;

	std::string company_name;
	std::string position;
	int annual_income;

public:
	static CPersonBuilder create();

	friend std::ostream& operator<<(std::ostream& os, const CPerson& obj) {
		os << "street_address: " << obj.street_address
			<< " post_code: " << obj.post_code
			<< " city: " << obj.city
			<< " company_name: " << obj.company_name
			<< " position: " << obj.position
			<< " annual_income: " << obj.annual_income;
		return os;
	}

	friend class CPersonAddressBuilder;
	friend class CPersonJobBuilder;
	friend class cPersonBuilder;

};

CPersonBuilder CPerson::create() 
{
	return CPersonBuilder(*(new CPerson()));
}
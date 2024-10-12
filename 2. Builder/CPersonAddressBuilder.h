#pragma once

#include "CPerson.h"
#include "CPersonBuilderBase.h"

class CPerson;
class CPersonBuilderBase;

class CPersonAddressBuilder : public CPersonBuilderBase
{
	typedef CPersonAddressBuilder self;

public:
	explicit CPersonAddressBuilder(CPerson& person)
	: CPersonBuilderBase{ person } { }

	self& at(std::string street_address)
	{
		person.street_address = street_address;
		return *this;
	}

	self& with_postcode(std::string post_code)
	{
		person.post_code = post_code;
		return *this;
	}

	self& in(std::string city)
	{
		person.city = city;
		return *this;
	}
};
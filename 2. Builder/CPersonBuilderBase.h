#pragma once

#include "CPerson.h"
#include "CPersonAddressBuilder.h"
#include "CPersonJobBuilder.h"

class CPerson;

class CPersonBuilderBase
{
protected:
	CPerson& person;
	
	explicit CPersonBuilderBase(CPerson& person)
	: person{ person } { }

	operator CPerson() const
	{
		return std::move(person);
	}

public:
	CPersonAddressBuilder lives() const;
	CPersonJobBuilder works() const;
};

CPersonAddressBuilder CPersonBuilderBase::lives() const 
{
	return CPersonAddressBuilder{ person };
}

CPersonJobBuilder CPersonBuilderBase::works() const 
{
	return CPersonJobBuilder{ person };
}
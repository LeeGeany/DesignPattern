#include "pimpl.h"

#include <iostream>

class Person::PersonImpl
{
public:
	void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
	std::cout << "hello " << p->name << "\n";
}

Person::Person()
: impl(new PersonImpl)
{
	name = "jh.lee";
}

Person::~Person()
{
	delete impl;
}

void Person::greet()
{
	impl->greet(this);
}
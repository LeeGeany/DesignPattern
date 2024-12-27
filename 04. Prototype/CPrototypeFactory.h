#pragma once

#include <memory>
#include <string>

class Address
{
public:
	Address(std::string _street, std::string _city, int _suite)
		: street(_street), city(_city), suite(_suite) {}

	Address(std::string& _street, std::string& _city, int& _suite)
		: street{ _street }, city{ _city }, suite{ _suite } {}
	virtual ~Address() {}

	std::string street;
	std::string city;
	int suite;
};

class Contact
{
public:
	Contact(std::string _name, Address* _address)
		: name(_name), address{ _address } { }

	Contact(const Contact& other)
		: name(other.name), address{ new Address{ *other.address } } { }
	virtual ~Contact() {}

	Contact& operator=(const Contact& other)
	{
		if (this == &other)
			return *this;

		name = other.name;
		address = other.address;
		return *this;
	}

	std::string name;
	Address* address;
};

class CPrototypeFactory
{
public:

	static Contact obj1;
	static Contact obj2;

	static std::unique_ptr<Contact> newObj1(std::string name, int suite)
	{
		return NewObj(name, suite, obj1);
	}

	static std::unique_ptr<Contact> newObj2(std::string name, int suite)
	{
		return NewObj(name, suite, obj2);
	}

private:
	static std::unique_ptr<Contact> NewObj(std::string name, int suite, Contact& proto)
	{
		auto result = std::make_unique<Contact>(proto);
		result->name = name;
		result->address->suite = suite;
		return result;
	}
};

Contact CPrototypeFactory::obj1{ "", new Address{ "1234 East Dr", "London", 0} };
Contact CPrototypeFactory::obj2{ "", new Address{"1235 East Dr", "London", 0} };
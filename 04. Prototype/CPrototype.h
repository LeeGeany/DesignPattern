#include <string>

class Address
{
public:
	Address(std::string _street, std::string _city, int _suite) 
	: street(_street), city(_city), suite(_suite){}
	virtual ~Address() {}

	std::string street;
	std::string city;
	int suite;
};

class Contact 
{
public:
	Contact(std::string _name, Address _address)
	: name(_name), address(_address){}
	virtual ~Contact() {}

	std::string name;
	Address address;
};

class Contact1
{
public:
	Contact1(const Contact1& other)
	: name(other.name)
	{
		address = new Address(
			other.address->street,
			other.address->city,
			other.address->suite
		);
	}
	virtual ~Contact1() {}

private:
	std::string name;
	Address* address;
};

class Address1
{
public:
	Address1(std::string _street, std::string _city, int _suite)
	: street(_street), city(_city), suite(_suite) {}

	Address1(std::string& _street, std::string& _city, int& _suite)
	: street{ _street }, city{ _city }, suite{ _suite } {}
	virtual ~Address1() {}

	std::string street;
	std::string city;
	int suite;
};

class Contact2
{
public:
	Contact2(std::string _name, Address1* _address)
	: name(_name), address{ _address } { }

	Contact2(const Contact2& other)
	: name(other.name), address{ new Address1{ *other.address } } { }
	virtual ~Contact2() {}

	Contact2& operator=(const Contact2& other)
	{
		if (this == &other)
			return *this;

		name = other.name;
		address = other.address;
		return *this;
	}

private:
	std::string name;
	Address1* address;
};
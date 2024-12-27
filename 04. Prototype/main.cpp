//#include "CPrototype.h"
#include "CPrototypeFactory.h"

int main(void)
{
	//Contact John("John Doe", Address{ "123 East DR", "London", 10 });
	//Contact Jake = John;

	//Contact2 worker{"", new Address1("123 East DR", "London", 10 )};
	//Contact2 John{ worker };
	//Contact2 Jane = John;

	auto obj1 = CPrototypeFactory::newObj1("Name", 100);

	return 0;
}


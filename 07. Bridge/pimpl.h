#include <string>

class Person
{
public:
	Person();
	virtual ~Person();

	void greet();

private:
	std::string name;

	// 클래스의 구현 부를 다른 클래스(PersonImple)에 숨기기 위해서 사용함
	class PersonImpl;
	PersonImpl* impl;
};
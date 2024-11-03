#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
	virtual string PhoneNumber() = 0;
	virtual string PhoneType() = 0;
};

class SamsungPhone : public Phone
{
public:
	virtual string PhoneNumber() override
	{
		return "010-0000-0000";
	}

	virtual string PhoneType() override
	{
		return "Samsung";
	}
};

class ApplePhone : public Phone
{
public:
	virtual string PhoneNumber() override
	{
		return "010-1111-1111";
	}

	virtual string PhoneType() override
	{
		return "Apple";
	}
};

class ShowPhoneInfo
{
private:
	Phone* m_Adaptor;

public:
	ShowPhoneInfo(Phone* _Adaptor) : m_Adaptor(_Adaptor)
	{

	}

	virtual ~ShowPhoneInfo()
	{

	}

	void ChangeAdaptor(Phone* _Adaptor)
	{
		m_Adaptor = _Adaptor;
	}

	void ShowInfo()
	{
		cout << "=================================" << endl;
		cout << "Phone Number : " << m_Adaptor->PhoneNumber() << endl;
		cout << "Phone Type   : " << m_Adaptor->PhoneType() << endl;
		cout << endl;
	}
};

int main(void)
{
	SamsungPhone* sPhone = new SamsungPhone();
	ApplePhone* aPhone = new ApplePhone();

	ShowPhoneInfo PhoneAdaptor(sPhone);

	PhoneAdaptor.ShowInfo();

	PhoneAdaptor.ChangeAdaptor(aPhone);

	PhoneAdaptor.ShowInfo();

	return 0;
}
#include <iostream>

class CSingletonOrigin
{
private:
	CSingletonOrigin() {}

public:
	//static CSingleton1& getIns()
	//{
	//	static CSingleton1 ins;
	//	return ins;
	//}

	static CSingletonOrigin* getIns()
	{
		static CSingletonOrigin* ins = new CSingletonOrigin();
		return ins;
	}

	CSingletonOrigin(CSingletonOrigin const&) = delete;
	CSingletonOrigin(CSingletonOrigin&&) = delete;
	CSingletonOrigin operator=(CSingletonOrigin const&) = delete;
	CSingletonOrigin operator=(CSingletonOrigin&&) = delete;

	void Function()
	{
		std::cout << "Singletone\n";
	}
};
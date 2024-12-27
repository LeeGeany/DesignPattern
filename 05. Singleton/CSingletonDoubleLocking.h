#include <iostream>

class CSingletonDoubleLocking
{
private:
	CSingletonDoubleLocking() {}

public:
	//static CSingleton1& getIns()
	//{
	//	static CSingleton1 ins;
	//	return ins;
	//}

	static CSingletonDoubleLocking* getIns()
	{
		static CSingletonDoubleLocking* ins = new CSingletonDoubleLocking();
		return ins;
	}

	CSingletonDoubleLocking(CSingletonDoubleLocking const&) = delete;
	CSingletonDoubleLocking(CSingletonDoubleLocking&&) = delete;
	CSingletonDoubleLocking operator=(CSingletonDoubleLocking const&) = delete;
	CSingletonDoubleLocking operator=(CSingletonDoubleLocking&&) = delete;

	void Function()
	{
		std::cout << "Singletone\n";
	}
};
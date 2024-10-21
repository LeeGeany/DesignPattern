#include "CSingleton.h"
#include "CSingletonOrigin.h"


//static CSingletone ins{};

CSingleton& getIns()
{
	static CSingleton ins{};
	return ins;
}

int main(void)
{
	// ins.Function();
	// getIns().Function();
	// CSingletonOrigin::getIns()->Function();
	return 0;
}


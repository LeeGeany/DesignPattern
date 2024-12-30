#include "Observer.h"

int main(void)
{
	Person p{ 20 };
	ConsolePersonObServer cpo;
	
	p.subscribe(&cpo);
	p.set_age(21);
	p.set_age(22);
	

	return 0;
}
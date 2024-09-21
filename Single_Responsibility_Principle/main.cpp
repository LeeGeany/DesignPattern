#include <iostream>

#include "CMemo.h"
#include "CSave.h"

int main(void)
{
	CMemo Memo("My Memo");
	Memo.add("This is first Memo");
	Memo.add("This is second Memo");
	Memo.add("This is third Memo");

	Memo.show();
	CSave::saveAsFile(Memo, "Memo2.txt");

	return 0;
}
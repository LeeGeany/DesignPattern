#include <iostream>

#include "memento.h"

int main(void)
{
	BankAccount bank{ 100 };
	auto m1 = bank.deposit(30);
	auto m2 = bank.deposit(40);

	std::cout << bank.balance << "\n";

	bank.restore(m1);
	std::cout << bank.balance << "\n";

	bank.restore(m2);
	std::cout << bank.balance << "\n";
}
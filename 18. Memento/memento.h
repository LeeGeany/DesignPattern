class BankAccount;

class Memento
{
	int balance;
public:
	Memento(int balance) :balance{ balance }
	{
	}

	friend class BankAccount;

};

class BankAccount
{
public:
	int balance;

public:
	explicit BankAccount(const int balance) : balance(balance) {}

	Memento deposit(int amount)
	{
		balance += amount;
		return balance;
	}

	void restore(const Memento& m)
	{
		balance = m.balance;
	}
};
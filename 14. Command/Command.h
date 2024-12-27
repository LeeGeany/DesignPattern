#include <iostream>
#include <vector>

class BandAccount
{
public:
	int balance = 0;
	int overdraft_limit = -500;

	void deposit(int amount)
	{
		balance += amount;
		std::cout << "deposited " << amount << ", balance is now " << balance << '\n';
	}

	bool withdraw(int amount)
	{
		
		if (balance - amount >= overdraft_limit)
		{
			balance -= amount;
			std::cout << "withdraw " << amount << ", balance is now " << balance << '\n';
			return true;
		}
		return false;
	}
};

class Command
{
public:
	virtual void call() = 0;
	virtual void undo() = 0;
};

class BandAccountCommand : public Command
{
public:
	BandAccount& account;
	enum Action { deposit, withdraw } action;
	int amount;
	bool withdrawal_succeeded;

	BandAccountCommand(BandAccount& account, const Action action, const int amount)
	: account(account), action(action), amount(amount), withdrawal_succeeded{false}
	{
	}

	virtual void call() override
	{
		switch (action)
		{
		case deposit:
			account.deposit(amount);
			break;
		case withdraw:
			withdrawal_succeeded = account.withdraw(amount);
			break;
		}
	}

	virtual void undo() override
	{
		switch (action)
		{
		case deposit:
			account.withdraw(amount);
			break;
		case withdraw:
			if(withdrawal_succeeded)
				account.deposit(amount);
			break;
		}
	}
};

class compsiteBandAccountCommand : public std::vector<BandAccountCommand>, public Command
{
public:
	compsiteBandAccountCommand(const std::initializer_list<value_type>& items)
	: vector<BandAccountCommand>(items)
	{
	}

	virtual void call() override
	{
		bool ok = true;
		for (auto& cmd : *this)
		{
			if (ok)
			{
				cmd.call();
				ok = cmd.withdrawal_succeeded;
			}
			else
			{
				cmd.withdrawal_succeeded = false;
			}
		}
	}

	virtual void undo() override
	{
		for (auto it = rbegin(); it != rend(); ++it)
		{
			it->undo();
		}
	}
};

class MoneyTransferCommand : public compsiteBandAccountCommand
{
public:
	MoneyTransferCommand(BandAccount& from, BandAccount& to, int amount)
		: compsiteBandAccountCommand{ BandAccountCommand{from, BandAccountCommand::Action::withdraw, amount}
									, BandAccountCommand{to, BandAccountCommand::Action::deposit, amount} }
	{
	}
};
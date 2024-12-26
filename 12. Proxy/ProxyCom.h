#include <string>

class pingable
{
public:
	virtual std::wstring ping(const std::wstring& message) = 0;
};

class pong : public pingable
{
	virtual std::wstring ping(const std::wstring& message) override
	{
		return message + L"pong";
	}
};

void tryit(pingable& pp)
{
	std::wcout << pp.ping(L"ping") << '\n';
}
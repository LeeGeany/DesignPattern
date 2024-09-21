#include "CMemo.h"

CMemo::CMemo(const std::string& title)
: title(title)
, count(1)
{

}

CMemo::~CMemo()
{

}

void CMemo::add(const std::string& entry)
{
	entries.push_back(std::to_string(count++) + ": " + entry);
}

void CMemo::show()
{
	for (auto iter : entries)
	{
		std::cout << iter << "\n";
	}
}

std::vector<std::string>& CMemo::GetEntries()
{
	return entries;
}


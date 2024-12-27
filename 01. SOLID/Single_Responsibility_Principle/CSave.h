#pragma once

#include "CMemo.h"

class CSave
{
public:
	static void saveAsFile(CMemo& memo, const std::string filename)
	{
		std::ofstream ofs;
		ofs.open(filename);
	
		for (auto& iter : memo.GetEntries())
		{
			ofs << iter << "\n";
		}
	
		ofs.close();
	}

	static void saveAsCloud(const CMemo& memo, const std::string ip, const std::string port)
	{
		//...
	}
};


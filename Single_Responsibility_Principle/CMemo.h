#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class CMemo
{
	std::string title;
	std::vector<std::string> entries;

	int count;

public:
	explicit CMemo(const std::string& title);
	virtual ~CMemo();

	void add(const std::string& entry);
	void show();

	std::vector<std::string>& GetEntries();

	/* ���� �κ��� ���� å�� ��Ģ���� ���ο� Ŭ������ ����� ����
	void saveAsFile(const std::string& filename);
	void saveAsCloud(const std::string& sendip, const std::string& port);
	*/
};


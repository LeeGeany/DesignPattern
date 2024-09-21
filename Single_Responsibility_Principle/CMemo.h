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

	/* 다음 부분은 단일 책임 원칙으로 새로운 클래스로 기능을 빼자
	void saveAsFile(const std::string& filename);
	void saveAsCloud(const std::string& sendip, const std::string& port);
	*/
};


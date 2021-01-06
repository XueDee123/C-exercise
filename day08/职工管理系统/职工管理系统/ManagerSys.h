#pragma once
#include<fstream>
#include<iostream>
#include"Staff.h"
#include "Boss.h"
#include "Manager.h"
#include "GeneralStaff.h"
#include <vector>

#define FILENAME "scaff.txt"

class ManagerSys
{
public:
	ManagerSys();
	~ManagerSys();
	int showMenu();
	void add();
	void showAll();
	void del();
	void exitSys();
	void updata();
	void find();
	void clear();
private:
	void save();
	int getWorkNum();
	void initWork();
	int isExist(int id);
	std::vector<std::string> split(const std::string& str, const std::string& pattern);

	Staff** _work;
	int _work_num;
	bool fileEmpty;
};


#pragma once
#include<string>
#include<iostream>
/// <summary>
/// Ô±¹¤
/// </summary>
class Staff
{
public:
	virtual void showInfo() = 0;
	virtual std::string getDeptName() = 0;
	std::string _name;
	int _no;
	int _deptId;
};


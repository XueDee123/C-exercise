#pragma once
#include<iostream>
class Base
{
public:
	Base():a(10)
	{
		std::cout << "Base无参构造" << std::endl;
	}
	~Base()
	{
		std::cout << "Base析构" << std::endl;
	}
	int a;
};


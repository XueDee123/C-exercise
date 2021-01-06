#pragma once
#include <iostream>
class Base
{
public:
	int a;
	Base():a(10)
	{}

	void func()
	{
		std::cout << "base.func" << std::endl;
	}
	void func(int a)
	{
		std::cout << "base.func(int)" << std::endl;
	}
};


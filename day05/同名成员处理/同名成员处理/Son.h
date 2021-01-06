#pragma once
#include "Base.h"
class Son : public Base
{
public:
	int a;
	Son():a(20)
	{}
	void func()
	{
		std::cout << "son.func" << std::endl;
	}
};


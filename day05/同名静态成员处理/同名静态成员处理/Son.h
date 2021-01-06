#pragma once
#include "Base.h"
class Son :    public Base
{
public:
	static int a;
	static void Func()
	{
		std::cout << "son func" << std::endl;
	}
};


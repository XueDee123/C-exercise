#pragma once
#include "Base.h"
class Son : public Base
{
public:
	Son():b(20)
	{
		std::cout << "Son�޲ι���" << std::endl;
	}
	~Son()
	{
		std::cout << "Son����" << std::endl;
	}
	int b;
};


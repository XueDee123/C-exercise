#pragma once
#include "Base.h"
class Son : public Base
{
public:
	Son():b(20)
	{
		std::cout << "Son无参构造" << std::endl;
	}
	~Son()
	{
		std::cout << "Son析构" << std::endl;
	}
	int b;
};


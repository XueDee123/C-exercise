#pragma once
#include "Base.h"
#include<iostream>
class Son :    public Base
{
public :
	void func()
	{
		std::cout << "son.func" << std::endl;
	}
};


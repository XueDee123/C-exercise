#pragma once
#include<iostream>
class Base
{
public:
	Base():a(10)
	{
		std::cout << "Base�޲ι���" << std::endl;
	}
	~Base()
	{
		std::cout << "Base����" << std::endl;
	}
	int a;
};


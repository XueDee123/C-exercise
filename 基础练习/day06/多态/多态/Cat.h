#pragma once
#include "Animal.h"
class Cat :    public Animal
{
public:
	void speak()
	{
		std::cout << "������" << std::endl;
	}
};


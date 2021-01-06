#pragma once
#include<iostream>
class Animal
{
public:

	virtual	void speak()
	{
		std::cout << "动物说话" << std::endl;
	}

};


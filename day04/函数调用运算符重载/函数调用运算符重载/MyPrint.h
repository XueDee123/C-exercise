#pragma once
#include<string>
#include<iostream>
class MyPrint
{

public:
	void operator()(std::string txt)
	{
		std::cout << txt << std::endl;
	}

};


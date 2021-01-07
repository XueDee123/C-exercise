#pragma once
#include<iostream>
class Person
{
public:
	int* Age;
	Person(int age)
	{
		Age = new int(age);
		std::cout << "有参构造" << std::endl;
	}
	Person(const Person& p)
	{
		Age = new int(*p.Age);
		std::cout << "拷贝构造" << std::endl;
	}
	Person& operator=(Person& p)
	{
		if (Age != NULL)
		{
			delete Age;
			Age = NULL;
		}
		Age = new int(*p.Age);
		std::cout << "=操作" << std::endl;
		return *this;
	}
	~Person()
	{
		if (Age != NULL)
		{
			delete Age;
			Age = NULL;
		}
		std::cout << "析构" << std::endl;
	}
};


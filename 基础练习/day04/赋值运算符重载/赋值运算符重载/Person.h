#pragma once
#include<iostream>
class Person
{
public:
	int* Age;
	Person(int age)
	{
		Age = new int(age);
		std::cout << "�вι���" << std::endl;
	}
	Person(const Person& p)
	{
		Age = new int(*p.Age);
		std::cout << "��������" << std::endl;
	}
	Person& operator=(Person& p)
	{
		if (Age != NULL)
		{
			delete Age;
			Age = NULL;
		}
		Age = new int(*p.Age);
		std::cout << "=����" << std::endl;
		return *this;
	}
	~Person()
	{
		if (Age != NULL)
		{
			delete Age;
			Age = NULL;
		}
		std::cout << "����" << std::endl;
	}
};


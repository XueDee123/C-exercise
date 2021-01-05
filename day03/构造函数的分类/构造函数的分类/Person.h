#pragma once
#include <iostream>
class Person
{
public:
	Person();
	Person(int a);
	Person(const Person& p);
	~Person();
	int age;
};


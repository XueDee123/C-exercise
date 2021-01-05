#pragma once
#include<string>
class Person
{

public:
	std::string name;
	int age;

public:
	Person(std::string name,int age):name(name),age(age)
	{}

	bool operator==(Person& p)
	{
		return (p.name == this->name && p.age == this->age) ? true : false;
	}
};


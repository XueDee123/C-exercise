#pragma once
#include<iostream>
class Person
{
public:
	Person();
	Person(int age,int height);
	Person(const Person& p);
	~Person();
	int age;
	int* height;
};


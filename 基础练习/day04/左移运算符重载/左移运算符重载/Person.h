#pragma once
#include<iostream>
class Person
{
	friend std::ostream& operator<<(std::ostream& cout, Person& p);
public:
	Person():m_A(100),m_B(200)
	{}
private:
	int m_A;
	int m_B;
};


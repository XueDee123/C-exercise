#pragma once
#include<iostream>
template<class T1,class T2>
class Person
{
public:
	T1 _name;
	T2 _age;
	Person(T1 t1, T2 t2);
	void showPerson();
};


template<class T1, class T2>
Person<T1, T2>::Person(T1 t1, T2 t2)
{
	_name = t1;
	_age = t2;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	std::cout << _name << std::endl;
	std::cout << _age << std::endl;
}
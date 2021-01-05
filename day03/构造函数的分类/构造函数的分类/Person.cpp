#include "Person.h"
Person::Person()
{
	std::cout << "Person的无参构造函数" << std::endl;
}
Person::Person(int a)
{
	this->age = a;
	std::cout << "Person的有参构造函数" << std::endl;
}
Person::Person(const Person& p)
{
	this->age = p.age;
	std::cout << "Person的拷贝构造函数" << std::endl;
}
Person::~Person()
{
	std::cout << "Person的析构函数" << std::endl;
}
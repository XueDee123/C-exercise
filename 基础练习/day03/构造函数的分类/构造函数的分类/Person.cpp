#include "Person.h"
Person::Person()
{
	std::cout << "Person���޲ι��캯��" << std::endl;
}
Person::Person(int a)
{
	this->age = a;
	std::cout << "Person���вι��캯��" << std::endl;
}
Person::Person(const Person& p)
{
	this->age = p.age;
	std::cout << "Person�Ŀ������캯��" << std::endl;
}
Person::~Person()
{
	std::cout << "Person����������" << std::endl;
}
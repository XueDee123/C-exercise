#include "Person.h"

Person::Person()
{
	std::cout << "�޲ι���" << std::endl;
}

Person::Person(int age, int height)
{
	this->age = age;
	this->height = new int(height);
	std::cout << "�вι���" << std::endl;
}

Person::Person(const Person& p)
{
	this->age = p.age;
	height =new int(* p.height);
	std::cout << "��������" << std::endl;
}

Person::~Person()
{
	delete height;
	height = NULL;
	std::cout << "����" << std::endl;
}

#include "Person.h"

Person::Person()
{
	std::cout << "无参构造" << std::endl;
}

Person::Person(int age, int height)
{
	this->age = age;
	this->height = new int(height);
	std::cout << "有参构造" << std::endl;
}

Person::Person(const Person& p)
{
	this->age = p.age;
	height =new int(* p.height);
	std::cout << "拷贝构造" << std::endl;
}

Person::~Person()
{
	delete height;
	height = NULL;
	std::cout << "析构" << std::endl;
}

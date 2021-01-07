

#include <iostream>
#include<string>

/*
* 类模板
*/
template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType n,AgeType a):_name(n),_age(a)
	{}
	NameType _name;
	AgeType _age;

};

void test()
{
	Person<std::string, int> p("Tom", 10);
	std::cout << p._name << std::endl;
	std::cout << p._age << std::endl;
}
int main()
{
	test();
    std::cout << "Hello World!\n";
}


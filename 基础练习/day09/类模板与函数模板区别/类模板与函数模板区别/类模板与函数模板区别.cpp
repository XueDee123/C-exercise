

#include <iostream>
#include<string>

/*
* 类模板与函数模板区别
* 类模板没有自动参数推导
* 类模板在模板参数列表可以又默认参数
*/

template<class NameType=std::string,class AgeType=int>
class Person
{
public:
	Person(NameType n, AgeType a):_name(n),_age(a)
	{}
	NameType _name;
	AgeType _age;
	void showPerson()
	{
		std::cout << "name:" << _name << "age:" << _age << std::endl;
	}
};

void test()
{
	Person<> p("Tom", 100);
	p.showPerson();
	Person<std::string,int> p2("Tom", 100);
	Person<std::string> p1("Tom", 100);
}


int main()
{
	test();
    std::cout << "Hello World!\n";
}


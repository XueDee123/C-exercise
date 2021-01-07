

#include <iostream>

/*
* 类模板中成员函数创建时机
* 类模板中成员函数在调用时才去创建
*/

class Person1
{
public:
	void showPerson1()
	{
		std::cout << "Person1" << std::endl;
	}

};
class Person2
{
public:
	void showPerson2()
	{
		std::cout << "Person2" << std::endl;
	}

};
template<class T>
class Person
{
public:
	T obj;
	//类模板中的成员函数
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test()
{
	Person< Person1>m;
	m.func1();
	//m.func2();
}
 

int main()
{
	test();
    std::cout << "Hello World!\n";
}


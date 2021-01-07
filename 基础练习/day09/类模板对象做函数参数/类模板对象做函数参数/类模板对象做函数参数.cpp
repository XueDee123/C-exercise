

#include <iostream>
#include<string>

/*
* 类模板对象做函数参数
* 1.指定传入类型
* 
* 2.参数模板化
* 
* 3.整个类模板化
*/

template<class T1,class T2>
class Person
{
public:
	Person(T1 t1,T2 t2):_name(t1),_age(t2)
	{}
	T1 _name;
	T2 _age;
	void show()
	{
		std::cout << "姓名：" << _name << "年龄：" << _age;
	}
};


//指定传入类型
void printPerson1(Person<std::string, int>& p)
{
	p.show();
}

//参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>& p)
{
	p.show();
	std::cout << "T1类型" << typeid(T1).name() << std::endl;
	std::cout << "T2类型" << typeid(T2).name() << std::endl;
}

//整个类模板化
template<class T>
void printPerson3(T& p)
{
	p.show();
	std::cout << "T的数据类型：" << typeid(T).name() << std::endl;
}
void test()
{
	Person<std::string, int> p("Tom", 10);
	printPerson1(p);
}
void test02()
{
	Person<std::string, int> p("Tom", 10);
	printPerson2(p);
}
void test03()
{
	Person<std::string, int> p("Tom", 10);
	printPerson3(p);
}
int main()
{
	//test();
	//test02();
	test03();
    std::cout << "Hello World!\n";
}


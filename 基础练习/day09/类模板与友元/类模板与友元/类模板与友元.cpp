
#include <iostream>
#include<string>

template<class T1, class T2>
class Person;
//2.全局函数类外实现
template<class T1, class T2>
void printfPerson2(Person<T1, T2>p)
{
	std::cout << p._name << std::endl;
	std::cout << p._age << std::endl;
}


template<class T1,class T2>
class Person
{
	//全局函数 类内实现
	friend void printfPerson(Person<T1, T2>p)
	{
		std::cout << p._name << std::endl;
		std::cout << p._age << std::endl;
	}
	//加一个空模板的参数列表
	//如果全局函数是类外实现，需要让编译器提前知道
	friend void printfPerson2<>(Person<T1, T2>p);

public:
	Person(T1 t1,T2 t2);
	

private:
	T1 _name;
	T2 _age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 t1, T2 t2):_name(t1),_age(t2)
{
}

//1.全局函数类内实现
void test()
{
	Person<std::string, int>p("Tom", 20);
	printfPerson(p);
}


void test2()
{
	Person<std::string, int>p("Jack", 201);
	printfPerson(p);
}
int main()
{
	test();
	test2();
    std::cout << "Hello World!\n";
}



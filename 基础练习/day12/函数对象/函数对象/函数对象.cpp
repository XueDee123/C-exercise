

#include <iostream>
#include<string>
using namespace std;

/*
* 函数对象-仿函数
* 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递
*/


//使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}

};
void test()
{
	MyAdd add;

	cout << add(10, 10) << endl;
}

//函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint():count(0)
	{}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count;
};
void test2()
{
	MyPrint p;
	p("haha");
	p("haha");
	p("haha");
	cout << p.count << endl;
}

//函数对象可以作为参数传递

void doPrint(MyPrint& p,string s)
{
	p(s);
}
void test3()
{
	MyPrint pp;
	doPrint(pp, "hahahha");
}

int main()
{
	test();
	test2();
	test3();

	std::cout << "Hello World!\n";
}


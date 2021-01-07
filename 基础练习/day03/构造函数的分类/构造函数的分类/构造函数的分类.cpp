

#include <iostream>
#include "Person.h"


void test()
{
	//括号法
	Person p1;//默认构造
	Person p2(10);//有参构造
	Person p3(p2);//拷贝构造函数


	//显示法
	Person p4;
	Person p5 = Person(10);
	Person p6 = Person(p5);

	//隐式转换法 
	Person p7 = 10; //相当于 Person p7 = Person(10);
	Person p8 = p7;
}


/*
 * 拷贝构造函数调用时机
 * 使用一个已经创建完毕的对象来初始化一个新对象
 * 值传递的方式给函数参数传值
 * 以值方式返回局部对象
 */

void test02()
{
	Person p1(20);
	Person p2(p1);
}
void doWork(Person p)
{
	std::cout << p.age << std::endl;
}

void test03()
{
	Person p1;
	doWork(p1);
}
Person doWork1()
{
	Person p1(10);
	return p1;
}
void test04()
{
	Person p1 = doWork1();
}

int main()
{
	//test();
	//test02();
	//test03();
	test04();
	std::cout << "Hello World!\n";
}


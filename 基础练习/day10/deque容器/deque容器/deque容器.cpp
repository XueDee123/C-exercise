

#include <iostream>
#include<deque>
#include<algorithm>
using namespace std;

void myPrint(const deque<int>&d)
{
	for (deque<int>::const_iterator i = d.begin(); i !=d.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}


//构造函数
void test()
{
    deque<int>d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	myPrint(d);

	deque<int>d2(d.begin(), d.end());
	deque<int>d3(10, 100);
	deque<int>d4(d);
}


//deque容器赋值操作
void test1()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myPrint(d1);

	deque<int>d2 = d1;
	myPrint(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	myPrint(d3);

}


//容器大小操作
void test2()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myPrint(d1);
	if (!d1.empty())
	{
		cout << "容器不为空" << endl;
		cout << d1.size() << endl;
	}
	else
	{
		cout << "容器为空" << endl;
	}

	d1.resize(5);
	myPrint(d1);
}


void test3()
{
	deque<int>d;
	//头插
	d.push_back(100);
	d.push_back(101);
	d.push_back(102);
	//尾插
	d.push_back(200);
	d.push_back(201);
	d.push_back(202);
	myPrint(d);
	//头删
	d.pop_front();
	myPrint(d);
	//尾删
	d.pop_back();
	myPrint(d);

}

//容器排序
void test4()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(1090);
	d.push_back(200);
	d.push_back(1000);
	myPrint(d);

	sort(d.begin(),d.end());
	myPrint(d);

}

int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	test4();
    std::cout << "Hello World!\n";
}


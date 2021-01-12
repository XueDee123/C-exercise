
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
* find
* 查找元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：查找的元素
*/


//查找内置的数据类型
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找下容器中是否有5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())cout << "未找到" << endl;
	else cout << "找到" << endl;
}

class Person
{
public:
	Person(string n, int a) :name(n), age(a)
	{}
	//需要重载== 让find知道如何对比
	bool operator==(const Person& p)
	{
		return this->age == p.age && this->name == p.name;
	}
	string name;
	int age;
};

//查找自定义的数据类型
void test1()
{
	vector<Person>v;
	v.push_back(Person("Tom", 10));
	v.push_back(Person("Jack", 20));
	v.push_back(Person("Make", 30));

	vector< Person>::iterator vp = find(v.begin(), v.end(), Person("Make", 30));

	if (vp == v.end())cout << "未找到" << endl;
	else cout << "找到" << endl;
}

int main()
{
	test();
	test1();
	std::cout << "Hello World!\n";
}


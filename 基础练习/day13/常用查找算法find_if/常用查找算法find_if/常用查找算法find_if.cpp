
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
* find_if
* 按条件查找元素
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：函数或谓词
*/

class GreaterFice
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};

//查找内置数据类型
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFice());
	if (it == v.end())cout << "未找到" << endl;
	else cout << "找到" << endl;
}

class Person
{
public:
	Person(string n, int a) :name(n), age(a)
	{}
	string name;
	int age;
};
class GreaterFice2
{
public:
	bool operator()(Person& p)
	{
		return p.age == 10 && p.name == "Tom1";
	}
};

//查找自定义数据类型
void test02()
{
	vector<Person>v;
	v.push_back(Person("Tom", 10));
	v.push_back(Person("Tom1", 11));
	v.push_back(Person("Tom2", 12));
	v.push_back(Person("Tom2", 13));
	vector<Person>::iterator it= find_if(v.begin(), v.end(), GreaterFice2());
	if (it == v.end())cout << "未找到" << endl;
	else cout << "找到" << endl;
}

int main()
{
	test01();
	test02();
	std::cout << "Hello World!\n";
}


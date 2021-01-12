
#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;



/*
* count_if
* 按条件统计元素个数
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：谓词
*/

class Condition
{
public:
	bool operator()(int v)
	{
		return v == 1;
	}
};

//统计内置数据类型
void test()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);

	cout << "1的个数" << count_if(v.begin(), v.end(), Condition()) << endl;
}


class Person
{
public:
	Person(string n, int a) :name(n), age(a)
	{

	}
	string name;
	int age;

};
class Condition1
{
public:
	bool operator()(const Person& p)
	{
		return p.name == "Tom";
	}
};

//统计自定义数据类型
void test1()
{
	vector<Person>v;
	v.push_back(Person("Tom", 20));
	v.push_back(Person("Tom1", 20));
	v.push_back(Person("Tom", 20));
	v.push_back(Person("Tom", 20));

	cout << "找到" << count_if(v.begin(), v.end(), Condition1()) << endl;
}

int main()
{
	test();
	test1();
	std::cout << "Hello World!\n";
}

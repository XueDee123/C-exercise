
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
* count
* 统计元素个数
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：统计的元素
*/


//统计内置数据类型
void test()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);

	int num = count(v.begin(), v.end(), 2);
	cout << "2的个数" << num << endl;
	int num1 = count(v.begin(), v.end(), 3);
	cout << "3的个数" << num1 << endl;
	int num2 = count(v.begin(), v.end(), 21);
	cout << "21的个数" << num2 << endl;
}

class Person
{
public:
	Person(string n, int a) :name(n), age(a)
	{}
	bool operator==(const Person& p)
	{
		return p.name == this->name;
	}
	string name;
	int age;
};

//统计自定义数据类型
void test1()
{
	vector<Person>v;
	v.push_back(Person("Tom", 10));
	v.push_back(Person("Tom1", 10));
	v.push_back(Person("Tom2", 10));
	v.push_back(Person("Tom1", 10));
	v.push_back(Person("Tom", 10));

	int num = count(v.begin(), v.end(), Person("Tom", 10));
	cout << "找到" << num << endl;
}

int main()
{
	test();
	test1();
	std::cout << "Hello World!\n";
}


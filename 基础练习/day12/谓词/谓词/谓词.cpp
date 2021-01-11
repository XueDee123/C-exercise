
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
* 谓词
* 返回bool类型的仿函数称为谓词
* 如果operator()接受一个参数，那么叫一元谓词
* 如果operator()接受两个参数，那么叫做二元谓词
*/


class GreaterFive
{
public:
	bool operator()(int a)
	{
		if (a > 5)return true;
		return false;
	}
};

//一元谓词
void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中大于5的数字
	//GreaterFive() 匿名函数对象
	vector<int>::iterator vp = find_if(v.begin(), v.end(), GreaterFive());
	GreaterFive gf;
	find_if(v.begin(), v.end(), gf);
	if (vp != v.end())cout << "找到大于5的数" << *vp << endl;
}


class MySort
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

//二元谓词
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), MySort());
	for (vector<int>::const_iterator i = v.begin(); i !=v.end(); i++)
	{
		cout << *i << endl;
	}
}


int main()
{
	test();
	test1();
	std::cout << "Hello World!\n";
}


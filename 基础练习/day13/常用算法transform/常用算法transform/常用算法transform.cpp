

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* transform
* 搬运容器到另一个容器中
* 形参1：源容器开始迭代器
* 形参2：源容器结束迭代器
* 形参3：目标容器开始迭代器
* 形参4：函数或者函数对象
*/

class trans
{
public:
	int operator()(int v)
	{
		return v;
	}

};
class print
{
public:
	void operator()(int v)
	{
		cout << v << endl;
	}
};


void test1()
{
	//源容器
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//目标容器
	vector<int>v2;
	//开辟空间
	v2.resize(v.size());
	//搬运数据
	transform(v.begin(), v.end(), v2.begin(), trans());
	for_each(v2.begin(), v2.end(), print());
}


int main()
{
	test1();
	std::cout << "Hello World!\n";
}


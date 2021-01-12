
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* sort
* 对容器内元素进行排序
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：谓词
*/
class ord
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
class print
{
public:
	void operator()(int v)
	{
		cout << v << " ";
	}
};


void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(1);
	v.push_back(30);
	v.push_back(20);
	v.push_back(100);
	v.push_back(101);

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print());
	cout << endl;

	sort(v.begin(), v.end(), ord());
	for_each(v.begin(), v.end(), print());
	cout << endl;
}

int main()
{
	test();
	std::cout << "Hello World!\n";
}


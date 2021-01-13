
#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>

/*
* set_union
* 求两个集合的并集 不重复的元素  注意集合必须是有序的
* 形参1：容器1开始迭代器
* 形参2：容器1结束迭代器
* 形参3：容器2开始迭代器
* 形参4：容器2结束迭代器
* 形参5：目标容器开始迭代器
*/
void print(int v)
{
	cout << v << " ";
}
void test()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	for_each(v2.begin(), v2.end(), print);
	cout << endl;
	vector<int>v3;
	//开辟空间
	v3.resize(v1.size()+ v2.size());
	vector<int>::iterator iend= set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), iend, print);
	cout << endl;
}


int main()
{
	test();
	std::cout << "Hello World!\n";
}


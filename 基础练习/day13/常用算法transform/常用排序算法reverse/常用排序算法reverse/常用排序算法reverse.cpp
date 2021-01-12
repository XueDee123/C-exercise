
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* reverse
* 将容器内元素进行反转
* 形参1：开始迭代器
* 形参2：结束迭代器
*/

void print(int v)
{
	cout << v << " ";
}
void test()
{
    vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
}

int main()
{
	test();
    std::cout << "Hello World!\n";
}

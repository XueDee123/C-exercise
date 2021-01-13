
#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

/*
* accumulate
* 头文件 numeric
* 计算累加和
* 形参1：起始迭代器
* 形参2：结束迭代器
* 形参3：起始累加值
*/

void test1()
{
    vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int total=accumulate(v.begin(), v.end(), 0);
	cout << "total=" << total << endl;
}

int main()
{
	test1();
    std::cout << "Hello World!\n";
}

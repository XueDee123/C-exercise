
#include <iostream>
#include <set>
#include<vector>
#include<algorithm>
using namespace std;


/*
* binary_search
* 查找指定元素是否存在
* 注意：在无序序列中不可用！！！！！！！！
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：查找的元素
*/
class print
{
public:
	void operator()(int v)
	{
		cout << v << endl;
	}
};

void test()
{
	set<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.insert(i);
	}
	for_each(v.begin(), v.end(), print());
	//查找2
	bool ret= binary_search(v.begin(), v.end(), 2);
	if (ret)cout << "找到" << endl;
	else cout << "未找到" << endl;
}


int main()
{
	test();
	std::cout << "Hello World!\n";
}


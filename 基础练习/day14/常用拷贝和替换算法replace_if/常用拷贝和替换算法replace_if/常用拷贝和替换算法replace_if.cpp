

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* replace_if
* 将区间内满足条件的元素，替换成指定元素
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：谓词
* 形参4：替换的新元素
*/
class rep
{
public:
	bool operator()(int v)
	{
		return v == 10;
	}
};
void print(int v)
{
	cout << v << " ";
}

void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(10);

	replace_if(v.begin(), v.end(), rep(), 200);
	for_each(v.begin(), v.end(), print);
	cout << endl;
}

int main()
{
	test();
	std::cout << "Hello World!\n";
}

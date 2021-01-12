
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


/*
* random_shuffle
* 洗牌 指定范围内的元素随机调整次序
* 形参1：开始迭代器
* 形参2：结束迭代器
*/

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
	//随机数种子
	srand(time(NULL));
	vector<int >v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print());
	cout << endl;

	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), print());
	cout << endl;

}

int main()
{

	test();
	std::cout << "Hello World!\n";
}

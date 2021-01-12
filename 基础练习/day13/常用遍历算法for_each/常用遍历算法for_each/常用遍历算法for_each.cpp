
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 常用遍历算法 for_each
*/

void print01(int va)
{
	cout << va << endl;
}
class print02
{
public:
	void operator()(int v)
	{
		cout << v << endl;
	}
};

void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print01);
	for_each(v.begin(), v.end(), print02());
}

int main()
{
	test();
	std::cout << "Hello World!\n";
}


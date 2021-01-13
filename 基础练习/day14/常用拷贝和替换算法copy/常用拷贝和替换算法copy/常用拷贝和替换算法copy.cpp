

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* copy
* 
*/
void print(int v)
{
	cout << v << " ";
}
void test01()
{
    vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	//必须要预先开辟空间
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print);
	cout << endl;
}

int main()
{
	test01();
    std::cout << "Hello World!\n";
}



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* replace
* 将容器内指定范围的旧元素修改成新元素
* 形参1：开始迭代器
* 形参2：结束迭代器
* 形参3：旧元素
* 行参4：新元素
*/
void print(int v)
{
    cout << v << " ";
}
void test()
{
    vector<int>v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(20);

    for_each(v.begin(), v.end(), print);
    cout << endl;

    replace(v.begin(), v.end(), 20, 2000);
    for_each(v.begin(), v.end(), print);
    cout << endl;
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


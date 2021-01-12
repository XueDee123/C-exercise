
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
* adjacent_find
* 查找相邻重复元素，返回相邻元素的第一个位置的迭代器
* 形参1：开始迭代器
* 形参2：结束迭代器
*/

void test()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator it= adjacent_find(v.begin(), v.end());
    if (it == v.end())cout << "未找到" << endl;
    else cout << "找到" << endl;
}


int main()
{
    test();
    std::cout << "Hello World!\n";
}


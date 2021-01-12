
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
* merge
* 两个容器元素合并，存储到领一容器中
* 注意：两个容器必须是有序的
* 形参1：容器1开始迭代器
* 形参2：容器1结束迭代器
* 形参3：容器2开始迭代器
* 形参4：容器2结束迭代器
* 形参6：目标开始迭代器
*/
void print(int v)
{
    cout << v << " ";
}
void test()
{
    vector<int> s1;
    for (int i = 0; i < 10; i++)
    {
        s1.push_back(i);
    }
    vector<int> s2;
    for (int i = 20; i < 30; i++)
    {
        s2.push_back(i);
    }
    vector<int>s3;
    //必须分配空间
    s3.resize(s1.size() + s2.size());
    merge(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
    for_each(s3.begin(), s3.end(), print);
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}

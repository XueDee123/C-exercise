

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

/*
* fill
* 填充
* 形参1：起始迭代器
* 形参2：结束迭代器
* 形参3：填充的值
*/
void print(int v)
{
    cout << v << " ";
}
void test()
{
    vector<int>v;
    v.resize(10);
    //重新填充
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), print);
}


int main()
{
    test();
    std::cout << "Hello World!\n";
}


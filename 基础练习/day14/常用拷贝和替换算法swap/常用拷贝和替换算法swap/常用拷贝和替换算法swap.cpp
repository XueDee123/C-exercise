
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* swap
* 互换两个容器的元素
* 形参1：容器1
* 形参2：容器2
*/
void print(int v)
{
    cout << v << " ";
}
void test()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for (int i = 20; i < 35; i++)
    {
        v2.push_back(i);
    }
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}

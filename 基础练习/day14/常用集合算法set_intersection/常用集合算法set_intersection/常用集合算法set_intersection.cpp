
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
* set_intersection
* 求两个容器的交集 重复的数
* 
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
        v2.push_back(i + 5);
    }
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
    vector<int> v3;
    //目标容器需要开辟空间
    //大容器包含小容器 ，取小容器
    v3.resize(min( v1.size() , v2.size()));
    //获取交集
   vector<int>::iterator iend= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
   for_each(v3.begin(), iend, print);


}


int main()
{
    test();
    std::cout << "Hello World!\n";
}

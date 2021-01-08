
#include <iostream>
#include<vector>
#include<algorithm>

/*
* vector 容器存放内置数据类型
*/

void myPrint(int val)
{
    std::cout << val << std::endl;
}

void test()
{
    //创建一个vector容器，数组
    std::vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过迭代器访问容器中的数据
    std::vector<int>::iterator itBegin = v.begin();//起始迭代器
    std::vector<int>::iterator itEnd = v.end();//结束迭代器
    //第一种
    while (itBegin != itEnd)
    {
        std::cout << *itBegin << std::endl;
        itBegin++;
    }
    //第二种
    for (std::vector<int>::iterator i = v.begin(); i !=v.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    //第三种
    std::for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


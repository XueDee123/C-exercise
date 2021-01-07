

#include <iostream>
#include "MyArray.hpp"
/*
* 实现一个通用数组类
* 1.可以对内置类型以及自定义数据类型的数据进行存储
* 2.将数组中的数据存储到堆区
* 3.构造函数中可以传入数组的容量
* 4.提供对应的拷贝构造以及operator=防止浅拷贝
* 提供尾插法和尾删除对数组里的数据进行添加删除
* 可以通过下标来访问
* 可以获取数组中当前元素个数和数组容量
*/
void test()
{
    MyArray<int> m;
    MyArray<int> m1(30);
    MyArray<int> m2(m);
    m2 = m1;
    for (int i = 0; i < 100; i++)
    {
        m2.Add(i);
    }
    std::cout << m2.getIndex() << std::endl;
    std::cout << m2.getCount() << std::endl;
    for (int i = 0; i < m2.getIndex(); i++)
    {
        std::cout << m2[i]<<" ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 100; i++)
    {
        m2.Remove();
    }
    std::cout << m2.getIndex() << std::endl;
    std::cout << m2.getCount() << std::endl;
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


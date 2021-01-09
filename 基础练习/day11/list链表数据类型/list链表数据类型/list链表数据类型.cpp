

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
/*
* list
*/

void myPrint(const list<int>& l)
{
    if (!l.empty())
    {
        for (list<int>::const_iterator i = l.begin(); i !=l.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
   
}

void test()
{
    list<int> l1;//默认构造
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    //遍历
    myPrint(l1);

    list<int>l2(l1.begin(), l1.end());
    myPrint(l2);

    list<int>l3(l2);
    myPrint(l3);

    list<int>l4(10, 1000);
    myPrint(l4);
}

void test1()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    myPrint(l1);

    list<int>l2 = l1;
    myPrint(l2);

    list<int>l3;
    l3.assign(l1.begin(),l1.end());
    myPrint(l3);

    list<int>l4(10, 1000);
    myPrint(l4);
    l1.swap(l4);
    myPrint(l1);
    myPrint(l4);
}

void test2()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    myPrint(l1);

    cout << l1.size() << endl;
    
    l1.resize(2);
    myPrint(l1);

    l1.resize(5,0);
    myPrint(l1);
}

void test3()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    l1.push_front(400);
    myPrint(l1);

    l1.pop_back();
    myPrint(l1);

    l1.pop_front();
    myPrint(l1);

    l1.insert(l1.begin(), 1000);
    myPrint(l1);

    l1.insert(l1.end(), 3000);
    myPrint(l1);

    l1.erase(l1.begin());
    myPrint(l1);

    l1.remove(20);
    myPrint(l1);

    l1.clear();
    myPrint(l1);
}

void test4()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout << l1.front() << endl;
    cout << l1.back() << endl;

}

bool myCompare(int v1, int v2)
{
    //降序
    return v1 > v2;
}

void test5()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    myPrint(l1);

    //反转
    l1.reverse();
    myPrint(l1);

    //不支持随机访问的迭代器不可以用标准的算法
    //不支持随机访问迭代器的容器，内部会提供一些算法
    l1.sort();
    myPrint(l1);

    //降序
    l1.sort(myCompare);
    myPrint(l1);
}

int main()
{
    //test();
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    std::cout << "Hello World!\n";
}


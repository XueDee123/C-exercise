

#include <iostream>
#include<string>
#include"Person.hpp"
using namespace std;
/*
* 类模板成员函数类外实现和分文件
* 将.h和.cpp的内容写在一起，将后缀名改成.hpp
*/

void test()
{
    Person<std::string, int> p("Tom", 100);
    p.showPerson();
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


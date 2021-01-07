

#include <iostream>
#include "MyInteger.h"

std::ostream& operator<<(std::ostream& cout, MyInteger p)
{
    cout << p.m_Num;
    return cout;
}

void test()
{
    MyInteger i;
   std:: cout << ++i << std::endl;
   std::cout << i << std::endl;
}
void test1()
{
    MyInteger i;
    std::cout << i++ << std::endl;
    std::cout << i << std::endl;
}
int main()
{
    test();
    test1();
    std::cout << "Hello World!\n";
}



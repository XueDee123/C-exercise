

#include <iostream>
#include "Person.h"

void test()
{
    Person p1(18);
    Person p2(20);
    p2 = p1;
    std::cout << "p1的Age=" << *p1.Age << std::endl;
    std::cout << "p2的Age=" << *p2.Age << std::endl;
}


int main()
{
    test();
    std::cout << "Hello World!\n";
}


#include "Person.h"
#include <iostream>

void test()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 == p2)std::cout << "p1 == p2" << std::endl;
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


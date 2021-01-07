

#include <iostream>
#include "Person.h"

void test()
{
    Person p1(20,160);
    Person p2(p1);
    std::cout << "p1.height->" << *p1.height << std::endl;
    std::cout << "p2.height->" << *p2.height << std::endl;
}



int main()
{
    test();
    std::cout << "Hello World!\n";
}


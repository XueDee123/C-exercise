

#include <iostream>
#include"Cat.h"

void test()
{
    Animal* p = new Cat("TOM");
    p->speak();
    delete p;
}


int main()
{
    test();
    std::cout << "Hello World!\n";
}


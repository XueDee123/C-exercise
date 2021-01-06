
#include <iostream>
#include "Son.h"

int Son::a = 200;
int Base::a = 100;

void test()
{
    Son s;
    std::cout << "son a " << s.a << std::endl;
    std::cout << "base a " << s.Base::a << std::endl;

    std::cout << "son a " << Son::a << std::endl;
    std::cout << "base a " << Base::a << std::endl;
    std::cout << "base a " << Son::Base::a << std::endl;

    s.Func();
    s.Base::Func();
    Son::Func();
    Base::Func();
    Son::Base::Func();
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


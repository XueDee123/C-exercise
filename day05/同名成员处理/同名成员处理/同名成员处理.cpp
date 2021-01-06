

#include <iostream>
#include"Son.h"

void test()
{
    Son s;
    std::cout << s.a << std::endl;
    std::cout << s.Base::a << std::endl;
    s.func();
    s.Base::func();
    s.Base::func(100);
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}



#include <iostream>
#include"Son.h"


void Test()
{
    Son s;
    std::cout << sizeof(Son) << std::endl;
    std::cout << s.Base1::a << std::endl;
}



int main()
{
    Test();
    std::cout << "Hello World!\n";
}


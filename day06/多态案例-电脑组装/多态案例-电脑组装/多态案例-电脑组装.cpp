

#include <iostream>
#include"Computer.h"
#include "Int.h"

void test()
{
    Int i;
    Computer c;
    c.doWork(&i, &i, &i);
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


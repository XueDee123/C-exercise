

#include <iostream>
#include "Son.h"


void doWork( Base* p)
{
    p->func();
}
void test()
{
    Son s;
    doWork(&s);
}


int main()
{
    test();
    std::cout << "Hello World!\n";
}


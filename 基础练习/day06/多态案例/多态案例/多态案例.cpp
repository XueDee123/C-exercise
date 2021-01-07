

#include <iostream>
#include"Coffee.h"

void doWork(Base* b)
{
    b->boilWater();
    b->brewing();
    b->pourIntoCup();
    b->excipientsAdded();
}
void test()
{
    Coffee c;
    doWork(&c);
}
int main()
{
    test();
    std::cout << "Hello World!\n";
}


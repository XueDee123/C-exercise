#include"MyAdd.h"
#include "MyPrint.h"
#include <iostream>

void test()
{
    MyPrint p;
    p("hahahahaha");
}
void test02()
{
    std::cout << MyAdd()(2, 3) << std::endl;
}
int main()
{
    test();
    test02();
    std::cout << "Hello World!\n";
}

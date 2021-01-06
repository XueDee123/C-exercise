

#include <iostream>
#include "Calculator.h"
#include "Add.h"

void test()
{
    Calculator c(10, 20);
    int res = c.getRes("+");
    std::cout << res << std::endl;
}
void cal(BaseCalculator& c)
{
    std::cout << c.getRes() << std::endl;
}
void test1()
{
    Add a(20, 30);
    cal(a);
}
int main()
{
    test();
    test1();
    std::cout << "Hello World!\n";
}



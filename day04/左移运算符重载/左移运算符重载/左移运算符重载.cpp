

#include <iostream>
#include "Person.h"

std::ostream& operator<<(std::ostream & cout,Person& p)
{
    cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
    return cout;
}

void test()
{
    Person p1;
    std::cout << p1 << std::endl;

}


int main()
{
    test();
    std::cout << "Hello World!\n";
}





#include <iostream>
#include "Person.h"

Person operator+(Person& p1, Person& p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
Person operator+(Person& p1, int p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2;
    temp.m_B = p1.m_B + p2;
    return temp;
}
void test()
{
    Person p1, p2;
    p1.m_A = 10;
    p1.m_B = 20;
    p2.m_A = 30;
    p2.m_B = 40;
    Person p3 = p1 + p2;
    std::cout << "p3.m_A" << p3.m_A << std::endl;
    std::cout << "p3.m_B" << p3.m_B << std::endl;
    Person p4 = p1 + 100;
    std::cout << "p4.m_A" << p4.m_A << std::endl;
    std::cout << "p4.m_B" << p4.m_B << std::endl;
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}



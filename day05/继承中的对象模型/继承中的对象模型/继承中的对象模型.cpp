

#include <iostream>
#include"Son.h"

void test()
{
    //16
    //父类中所有非静态成员属性都会被子类继承下来
    //父类中私有成员属性 是被编译器给隐藏了
    std::cout << sizeof(Son) << std::endl;

}


int main()
{
    test();
    std::cout << "Hello World!\n";
}


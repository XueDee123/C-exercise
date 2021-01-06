

#include <iostream>
#include"Cat.h"
#include "Dog.h"

//地址早绑定 在编译阶段就确定了函数地址
//如果想执行猫说话，那么函数地址不能早绑定，需要晚绑定
void doSpeak(Animal& a)
{
    a.speak();
}
void test()
{
    Cat c;
    doSpeak(c);
    Dog d;
    doSpeak(d);
    Animal a;
    doSpeak(a);
}
int main()
{
    test();
    std::cout << "Hello World!\n";
}



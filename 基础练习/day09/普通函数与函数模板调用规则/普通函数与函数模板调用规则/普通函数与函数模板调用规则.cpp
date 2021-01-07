

#include <iostream>

/*
* 如果函数模板和普通函数都可以调用，优先调用普通函数
* 可以通过空模板参数列表 强制调用函数模板
* 函数模板可以发生函数重载
* 如果函数模板可以产生更好的匹配，优先函数模板
*/

void myPrint(int a, int b)
{
    std::cout << "普通函数" << std::endl;
}
 
template<typename T>
void myPrint(T& a, T& b)
{
    std::cout << "函数模板" << std::endl;
}
template<typename T>
void myPrint(T& a, T& b,T &c)
{
    std::cout << "重载函数模板" << std::endl;
}
void test()
{
    int a = 10;
    int b = 20;
    int c = 100;
    //这里调用的是普通函数
    myPrint(a, b);

    //通过空模板的参数列表来调用函数模板
    myPrint<>(a, b);

    //重载函数模板
    myPrint(a, b, c);

    //如果函数模板可以产生更好的匹配，优先函数模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);
}
int main()
{
    test();
    std::cout << "Hello World!\n";
}


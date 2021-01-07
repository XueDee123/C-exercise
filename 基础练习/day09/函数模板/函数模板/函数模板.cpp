

#include <iostream>


//两个整型交换函数
void swapInt(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
//两个浮点型交换函数
void swapDouble(double& a, double& b)
{
    double t = a;
    a = b;
    b = t;
}
void test()
{
    int a = 10,b=20;
    swapInt(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    double c = 10.2, d = 20.3;
    swapDouble(c, d);
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
}

//函数模板
template<typename T> //声明一个模板 告诉编译器 T是一个通用数据类型
void mySwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
 
void test1()
{
    int a = 100, b = 200;
    //自动推导
    mySwap(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    //显示指定类型
    mySwap<int>(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

int main()
{
    test();
    test1();
    std::cout << "Hello World!\n";
}

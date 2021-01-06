

#include <iostream>
#include"Cpp.h"
#include "Java.h"

void test()
{
    std::cout << "java下载视频页面如下" << std::endl;
    Java j;
    j.header();
    j.left();
    j.content();
    j.footer();
    std::cout << "----------------------" << std::endl;
    std::cout << "C++下载视频页面如下" << std::endl;
    Cpp c;
    c.header();
    c.left();
    c.content();
    c.footer();
    std::cout << "----------------------" << std::endl;
}


int main()
{
    test();
    std::cout << "Hello World!\n";

}


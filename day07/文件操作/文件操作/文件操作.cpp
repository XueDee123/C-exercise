
#include<fstream>
#include <iostream>

//文本文件写文件

void test()
{
    //1.包含头文件
    //2.创建流
    std::ofstream ofs;
    //3.打开方式
    ofs.open("test.txt", std::ios::out);
    //4.写内容
    ofs << "这是测试信息1" << std::endl;
    ofs << "这是测试信息2" << std::endl;  
    ofs << "这是测试信息3" << std::endl;
    //5.关闭
    ofs.close();
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}



#include <iostream>
#include<string>
#include<fstream>

void test()
{
    std::ofstream ofs;
    ofs.open("test.txt", std::ios::out);
    ofs << "这是测试信息" << std::endl;
    ofs.close();
}
void test1()
{
    //1.包含头文件
    //2.创建流
    std::ifstream ifs;
    //3.打开文件 判断是否打开成功
    ifs.open("test.txt", std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    //4.读数据
    //1.
    {
        /*char buf[1024] = { 0 };
        while (ifs >> buf)
        {
            std::cout << buf << std::endl;
        }*/
    }
    //2
    {
       /* char buf[1024] = { 0 };
        while (ifs.getline(buf,sizeof(buf)))
        {
            std::cout << buf << std::endl;
        }*/
    }
    //3
    {
        std::string buf;
        while (std::getline(ifs, buf))
        {
            std::cout << buf << std::endl;
        }
    }//4
    {
       /* char c;
        while ((c = ifs.get()) != EOF)
        {
            std::cout << c;
        }*/
    }
    //5.关闭
    ifs.close();
}

int main()
{
    //test();
    test1();
    std::cout << "Hello World!\n";
}

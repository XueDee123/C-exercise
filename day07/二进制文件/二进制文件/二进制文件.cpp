

#include<fstream>
#include <iostream>
#include"Person.h"
//二进制写
void test()
{
    std::ofstream ofs;
    ofs.open("person.txt", std::ios::out | std::ios::binary);
    Person p ;
    ofs.write((const char*)&p, sizeof(Person));
    ofs.close();
}
//二进制读
void test1()
{
    std::ifstream ifs;
    ifs.open("person.txt", std::ios::in | std::ios::binary);
    if (!ifs.is_open())
    {
        std::cout << "读取文件失败" << std::endl;
        return;
    }
    Person s;
    ifs.read((char*)&s, sizeof(Person));
    std::cout << s.name << std::endl;
    std::cout << s.age << std::endl;
    ifs.close();

}
int main()
{
    //test();
    test1();
    std::cout << "Hello World!\n";
}

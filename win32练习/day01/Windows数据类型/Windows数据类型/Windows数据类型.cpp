
#include<Windows.h>
#include <iostream>

void test()
{
    LPSTR str =(LPSTR) "这个是windows字符串类型";
    std::cout << str << std::endl;
    CHAR lpstr[120] = "这是windows字符数组类型";
    std::cout << lpstr << std::endl;
    INT a = 100;
    DWORD d = 0xffff;
    MessageBoxA(NULL, str, "LPSTR", MB_OK);

}

int main()
{
    test();
    std::cout << "Hello World!\n";
    return 0;
}


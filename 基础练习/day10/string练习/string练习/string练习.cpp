
#include <iostream>
#include <string>
using namespace std;
/*
* 
*/

void test()
{
    std::string s;//默认构造
    const char* str = "hello";
    std::string s2(str);
    std::cout << s2 << std::endl;

    std::string s3(s2);
    std::cout << s3 << std::endl;

    std::string s4(10, 'a');
    std::cout << s4 << std::endl;

}

void test1()
{
    std::string s1;
    s1 = "hello";
    std::cout << "s1=" << s1 << std::endl;

    std::string s2;
    s2 = s1;
    std::cout << "s2=" << s2 << std::endl;

    std::string s3;
    s3 = 'a';
    std::cout << "s3=" << s3 << std::endl;

    std::string s4;
    s4.assign("hello");
    std::cout << "s4=" << s4 << std::endl;

    std::string s5;
    s4.assign("hello",3);//把字符串前几个字符复制
    std::cout << "s5=" << s5 << std::endl;

    std::string s6;
    s4.assign(s5);
    std::cout << "s6=" << s6 << std::endl;

    std::string s7;
    s4.assign(10,'a');
    std::cout << "s7=" << s7 << std::endl;

}

void test3()
{
    string st1 = "wo";
    st1 += "hah";
    cout << st1 << endl;
    st1 += ':';
    cout << st1 << endl;
    string s2 = "haha";
    st1 += s2;
    cout << st1 << endl;

    string s3 = "11";
    s3.append("haha");
    cout << s3 << endl;
    s3.append("haha",2);
    cout << s3 << endl;
}

int main()
{
    test();
    test1();
    test3();
    std::cout << "Hello World!\n";
}


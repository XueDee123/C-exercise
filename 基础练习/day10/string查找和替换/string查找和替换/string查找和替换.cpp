

#include <iostream>
#include<string>
using namespace std;


//查找
void test()
{
    string str1 = "abcdefg";
    int pos=str1.find("de1");
    cout << pos << endl;

    pos = str1.rfind("de");
    cout << pos << endl;

    /*
    * find和rfind区别
    * find是从左往右查找
    * rfind是从右往左查找
    */
}
//替换
void test02()
{
    string s1 = "abcdefg";
    s1.replace(1, 3, "1111");
    cout << s1 << endl;
}

int main()
{
    test();
    test02();
    std::cout << "Hello World!\n";
}




#include <iostream>
#include<string>

using namespace std;

void test()
{
    string str1 = "hello";
    string str2 = "hello";
    if (str1.compare(str2))
    {
        cout << "字符串相等" << endl;
    }
    else
    {
        cout << "字符串不相等" << endl;
    }
}

void test2()
{
    string s = "abcdef";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " "; 
    }
}

void test3()
{
    string s = "abcdef";
    s.insert(1, "111");
    cout << s << endl;

    s.erase(1, 3);
    cout << s << endl;
}

void test4()
{
    string s = "abcdef";
    string s1 = s.substr(1, 3);
    cout << s1 << endl;
}

int main()
{
    test();
    test3();
    test4();
    std::cout << "Hello World!\n";
}




#include <iostream>
#include <stack>
using namespace std;

/*
* 栈
*/


void test()
{
    stack<int> s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    //只要栈不为空，就一直出栈
    while (!s.empty())
    {
        cout << "栈顶元素" << s.top() << endl;
        //出栈
        s.pop();
    }
    cout << "栈的大小" << s.size() << endl;
}



int main()
{
    test();
    std::cout << "Hello World!\n";
}


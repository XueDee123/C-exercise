

#include <iostream>
#include <string>
/*
* 类模板与继承
*/
template<class T>
class Base
{
public:
    T m;
};
//必须要知道父类T的数据类型
class Son:public Base<int>
{
public:

};

//如果想灵活指定父类T类型，子类也需要变成类模板
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
    T1 t1;
};



void test()
{
    Son s1;
}

void test1()
{
    Son2<int, std::string> s2;
}

int main()
{
    test();
    test1();
    std::cout << "Hello World!\n";
}



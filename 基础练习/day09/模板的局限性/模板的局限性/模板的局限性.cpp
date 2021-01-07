

#include <iostream>


/*
* 模板局限性
* 模板不是万能的，有些特定数据类型，需要用具体化方式做特殊实现
*/

class Person
{
public:
	Person(std::string n,int a):_name(n),_age(a)
    {}
    std::string _name;
    int _age;

};



template<class T>
bool myCompare(T& a, T& b)
{
    return a == b ? true : false;
}

//利用具体化Person的版本
template<>bool myCompare(Person& a, Person& b)
{
    if (a._name == b._name && a._age == b._age)return true;
    return false;
}

void test()
{
    int a = 10;
    int b = 20;
    bool ret = myCompare(a, b);
    std::cout << ret << std::endl;
}
void test1()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    bool ret = myCompare(p1, p2);
    std::cout << ret << std::endl;
}

int main()
{
    test();
    test1();
    std::cout << "Hello World!\n";
}



#include <iostream>
#include<set>
#include<algorithm>
using namespace std;

class PP
{
public:
    bool operator()(int v1, int v2)const
    {
        return v1 > v2;
    }


};

void myPrint1( set<int,PP>& s1)
{
    if (!s1.empty())
    {
        cout << "容器中有:" << s1.size() << endl;
        for (set<int, PP>::iterator i = s1.begin(); i != s1.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
}
void myPrint(const set<int>&s1)
{
    if (!s1.empty())
    {
        cout << "容器中有:" << s1.size() << endl;
        for (set<int>::const_iterator i = s1.begin(); i !=s1.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
}
void myPrint(const multiset<int>& s1)
{
    if (!s1.empty())
    {
        cout << "容器中有:" << s1.size() << endl;
        for (multiset<int>::const_iterator i = s1.begin(); i != s1.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
}

void test()
{
    set<int>s1;

    //插入数据 只有 insert
    s1.insert(3);
    s1.insert(987);
    s1.insert(99);
    s1.insert(100);
    s1.insert(1);
    myPrint(s1);

    set<int>s2(s1);
    myPrint(s2);

    set<int>s3 = s1;
    myPrint(s3);

    set<int>s4;
    s4.insert(31);
    s4.insert(97);
    s4.insert(9987);
    s4.insert(1010);
    s4.insert(124);
    myPrint(s4);

    //查找
    set<int>::iterator p = s1.find(1);
    if (p != s1.end())cout << "找到元素" << endl;

    //统计
    int num = s1.count(1);


    //交换
    s1.swap(s4);
    myPrint(s1);
    myPrint(s4);

    //删除指定元素
    s1.erase(31);
    myPrint(s1);

    s1.erase(s1.begin());
    myPrint(s1);

    s1.erase(s1.begin(),s1.end());
    myPrint(s1);

    s1.clear();
}

void test1()
{
    set<int>s1;
    s1.insert(3);
    pair<set<int>::iterator,bool>ret=  s1.insert(3);//这个会插入失败，set不允许插入重复值
    if (ret.second)cout << "成功" << endl;
    else cout << "失败" << endl;
    myPrint(s1);

    multiset<int> s2;//允许插入重复的值
    s2.insert(3);
    s2.insert(3);
    myPrint(s2);
}

void test2()
{
    pair<string, int>p("TOM",1);
    cout << p.first << p.second << endl;

    pair<string, int>p2 = make_pair("jack", 20);
    cout << p2.first << p2.second << endl;
}





void test3()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(150);
    myPrint(s1);

    //指定排序规则
    set<int, PP>s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);
    s2.insert(150);
    myPrint1(s2);
}

class Person
{
public:
    Person(string n,int a):_name(n),_age(a)
    {}
    string _name;
    int _age;

private:

};

class MyPP
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
        return p1._age > p2._age;
	}

};



void test4()
{
    set<Person, MyPP>p;
    p.insert(Person("张三", 10));
    p.insert(Person("李四", 20));
    p.insert(Person("王五", 40));
    p.insert(Person("赵六", 10));
    p.insert(Person("Tom", 80));

    for (set<Person, MyPP>::iterator i = p.begin(); i!=p.end(); i++)
    {
        cout << i->_name << " " << i->_age<<endl;
    }
}

int main()
{
    //test();
    //test1();
    //test2();
    //test3();
    test4();
    std::cout << "Hello World!\n";
}



#include <iostream>
#include <map>
using namespace std;

void Myprint(const map<int,int>& m)
{
    if (!m.empty())
    {
        cout << "容器里有" << m.size() << endl;
        for (map<int, int>::const_iterator i = m.begin(); i !=m.end() ; i++)
        {
            cout << "key:" << (*i).first << "value:" << (*i).second<<endl;
        }
    }
}

void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 10));
    m.insert(pair<int, int>(3, 10));
    Myprint(m);

    map<int, int>::iterator ret = m.find(2);
    if (ret != m.end())cout << "找到" << endl;


    map<int, int>m1;
    m1.insert(pair<int, int>(2, 10));
    m1.insert(pair<int, int>(0, 10));
    m1.insert(pair<int, int>(3, 10));
    m1.insert(make_pair(6, 10));
    Myprint(m1);

    m.swap(m1);
    Myprint(m);
    Myprint(m1);

    //删除 key
    m.erase(6);
    m.erase(m.begin());
    m.clear();


}

class MyCom
{
public:
    bool operator()(int v1, int v2)const
    {
        return v1 > v2;
    }

private:

};


void test1()
{
    map<int, int, MyCom>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 10));
    m.insert(pair<int, int>(3, 10));
    for (map<int, int, MyCom>::const_iterator i = m.begin(); i != m.end(); i++)
    {
        cout << "key:" << (*i).first << "value:" << (*i).second << endl;
    }
}

int main()
{
    //test();
    test1();
    std::cout << "Hello World!\n";
}


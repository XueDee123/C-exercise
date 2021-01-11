

#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

/*
* STL内建了一些函数对象
* 算术仿函数
* 关系仿函数
* 逻辑仿函数
* 使用内建仿函数需要头文件 #include<functional>
*/

//算术仿函数
/*
* 仿函数原型
* template<class T>T plus<T>  加法仿函数
* template<class T>T minus<T>  减法仿函数
* template<class T>T multiplies<T>  乘法仿函数
* template<class T>T divides<T>  除法仿函数
* template<class T>T modulus<T>  取模仿函数
* template<class T>T negate<T>  取反仿函数
*/
void test()
{
    plus<int> p;
    cout << "10+20=" << p(10, 20) << endl;
    negate<int> n;
    cout << "取反后" << n(50) << endl;
}
//关系仿函数
/*
* 仿函数原型
*  template<class T>bool equal_to<T>   等于
*  template<class T>bool not_equal_to<T>   不等于
*  template<class T>bool greater<T>   大于
*  template<class T>bool greater_equal<T>   大于等于
*  template<class T>bool less<T>   小于
* template<class T>bool less_equal<T>   小于等于
*/
void test1()
{
    if (equal_to<int>()(10, 20))
    {
        cout << "等于" << endl;
    }
    else
    {
        cout << "不等于" << endl;
    }
}

//逻辑仿函数
/*
* 仿函数原型
* template<class T>bool logical_and<T>   逻辑与
* template<class T>bool logical_or<T>   逻辑或
* template<class T>bool logical_not<T>   逻辑非
*/
void test2()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    for (vector<bool>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    //利用逻辑非  将容器v 搬运到 容器v2中，并执行取反
    vector<bool>v2;
    //必须提前开辟空间
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator i = v2.begin(); i != v2.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    test();
    test1();
    test2();
    std::cout << "Hello World!\n";
}


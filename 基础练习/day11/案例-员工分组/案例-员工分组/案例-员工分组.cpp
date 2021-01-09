

#include <iostream>
#include <string>
#include <ctime>
#include<map>
using namespace std;

/*
* 公司招募了10名员工(ABCDEFGHIJ)
* 员工信息
*   姓名 工资 部门
* 随机给员工分配部门和工资
* 分部门显示
*/

class Person
{
public:
	Person(string n,int w):_name(n),_wag(w)
	{}
	string _name;
	int _wag;

};


void test()
{
	multimap<int, Person>m;
	m.insert(make_pair((rand() % 3) + 1, Person("A", (rand() % 5000)+5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("B", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("C", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("D", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("E", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("F", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("G", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("H", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("I", (rand() % 5000) + 5000)));
	m.insert(make_pair((rand() % 3) + 1, Person("J", (rand() % 5000) + 5000)));

	for (multimap<int, Person>::iterator i = m.begin(); i !=m.end(); i++)
	{
		cout << "部门：" << (*i).first << " 姓名：" << (*i).second._name << " 工资：" << (*i).second._wag << endl;
	}
}



int main()
{
	srand(time(0));
	test();
    std::cout << "Hello World!\n";
}


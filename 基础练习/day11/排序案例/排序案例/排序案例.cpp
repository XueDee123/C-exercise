

#include <iostream>
#include <string>
#include <list>

/*
* 将Person自定义数据类型进行排序
* 该类属性有姓名、年龄、身高
* 规则
*   按照年龄进行升序，如果年龄相同则按照身高进行降序
*/

class Person
{
public:
	Person(std::string n,int a,int h):_name(n),_age(a),_height(h)
	{}
	std::string _name;
	int _age;
	int _height;
private:

};
void myPrint(const std::list<Person>& p)
{
	if(!p.empty())
	{
		std::cout << "当前有" << p.size() << std::endl;
		for (std::list<Person>::const_iterator i = p.begin(); i !=p.end(); i++)
		{
			std::cout << "姓名" << i->_name << "年龄" << i->_age << "身高" << i->_height << std::endl;
		}
	}
}
bool myComp(Person p1, Person p2)
{
	if (p1._age == p2._age)
	{
		return p1._height > p2._height;
	}
	return p1._age < p2._age;
}

void test()
{
	std::list<Person> l;
	l.push_back(Person("Tom", 20, 183));
	l.push_back(Person("Tom1", 20, 153));
	l.push_back(Person("Tom2", 16, 153));
	l.push_back(Person("Tom3", 10, 103));
	myPrint(l);

	std::cout << "排序后" << std::endl;
	l.sort(myComp);
	myPrint(l);
}

int main()
{
	test();
    std::cout << "Hello World!\n";
}


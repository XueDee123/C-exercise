

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

/*
* vector容器存放自定义数据类型
*/
template<class T1,class T2>
class Person
{
public:
	Person(T1 t1,T2 t2):_name(t1),_age(t2)
	{}
	T1 _name;
	T2 _age;

private:

};

void myPrint(Person<std::string, int>i)
{
	std::cout << i._name << " " << i._age << std::endl;
}

void test()
{
	std::vector<Person<std::string, int>>v;
	v.push_back(Person<std::string, int>("Tom", 10));
	v.push_back(Person<std::string, int>("Jack", 20));
	v.push_back(Person<std::string, int>("Mike", 30));

	//one
	std::vector<Person<std::string, int>>::iterator vBegin = v.begin();
	std::vector<Person<std::string, int>>::iterator vEnd = v.end();
	while (vBegin!=vEnd)
	{
		std::cout << (*vBegin)._name << " " << (*vBegin)._age << std::endl;
		vBegin++;
	}


	//two
	for (std::vector<Person<std::string,int>>::iterator i = v.begin(); i !=v.end(); i++)
	{
		std::cout << (*i)._name << " " << (*i)._age << std::endl;
	}

	//three
	std::for_each(v.begin(), v.end(), myPrint);
}
void test1()
{
	//存放指针
	std::vector<Person<std::string, int>*>v;
	v.push_back(new Person<std::string, int>("Tom", 10));
	v.push_back(new Person<std::string, int>("Jack", 20));
	v.push_back(new Person<std::string, int>("Mike", 30));

	for (std::vector<Person<std::string,int>*>::iterator i = v.begin(); i!=v.end(); i++)
	{
		std::cout << (*i)->_name << " " << (*i)->_age << std::endl;
	}
	for (std::vector<Person<std::string, int>*>::iterator i = v.begin(); i != v.end(); i++)
	{
		delete* i;
	}
	v.clear();
}

int main()
{
	test();
	test1();
    std::cout << "Hello World!\n";
}


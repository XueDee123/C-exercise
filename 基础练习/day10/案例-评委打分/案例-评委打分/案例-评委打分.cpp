
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include<ctime>

using namespace std;
/*
* 案例描述
* 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，除去最高分，除去最低分，取平均
*/

class Person
{
public:
	Person(deque<int> d):_fraction(d)
	{}
	Person(){}
	deque<int>_fraction;
	void average()
	{
		sort(_fraction.begin(), _fraction.end());
		_fraction.pop_front();
		_fraction.pop_back();
		int num = 0;
		for (deque<int>::iterator i = _fraction.begin(); i != _fraction.end(); i++)
		{
			num += *i;
		}
		cout << "平局成绩：" << num / _fraction.size() << endl;
	}
private:

};



void test()
{
    
	vector<Person> v;
	for (int i = 0; i < 5; i++)
	{
		cout << "给" << i << "开始打分" << endl;
		Person p;
		for (int i = 0; i < 10; i++)
		{
			int u = rand() % 100;
			p._fraction.push_back(u);
			cout << u << " ";
		}
		v.push_back(p);
		cout << endl;
	}
	for (vector<Person>::iterator i = v.begin(); i !=v.end(); i++)
	{
		(*i).average();
	}
}


int main()
{
	srand(time(0));
	test();
    std::cout << "Hello World!\n";
}

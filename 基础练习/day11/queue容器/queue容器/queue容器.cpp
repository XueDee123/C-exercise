

#include <iostream>
#include <queue>
using namespace std;
/*
* queue 队列
*/


void test()
{
    queue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);
		cout << "入队" << i << " ";
	}
	cout << endl << "当前队列里有" << q.size() << endl;
	while (!q.empty())
	{
		cout << "出队" << q.front() << " ";
		q.pop();
	}
	cout << endl << "当前队列里有" << q.size() << endl;
}

int main()
{
	test();
    std::cout << "Hello World!\n";
}


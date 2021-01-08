
#include <iostream>
#include <vector>

using namespace std;


void myPrintVec(vector<int>& p)
{
	vector<int>::iterator i;
	for ( i = p.begin(); i !=p.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}


//vector容器构造
void test()
{
    vector<int> v1;//无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrintVec(v1);

	vector<int> v2(v1.begin(), v1.end());
	myPrintVec(v2);

	vector<int>v3(10, 100);
	myPrintVec(v3);
}


//vector 的赋值
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrintVec(v1);

	vector<int> v2 = v1;
	myPrintVec(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	myPrintVec(v3);

	vector<int>v4;
	v4.assign(10, 100);
	myPrintVec(v4);
}


//vector 容量和大小
void test2()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrintVec(v1);

	if (!v1.empty())//判断容器是否是空
	{
		cout << "容器不为空" << endl;
		cout << "容量"<<v1.capacity() << endl;
		cout << "大小" << v1.size() << endl;
	}
	else
	{
		cout << "容器为空" << endl;
	}

}

//插入和删除
void test3()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrintVec(v1);

	v1.pop_back();//尾删
	myPrintVec(v1);

	v1.insert(v1.begin(), 200);//插入
	myPrintVec(v1);

	v1.insert(v1.begin(), 2, 99);
	myPrintVec(v1);

	v1.erase(v1.begin());//删除
	myPrintVec(v1);

	v1.erase(v1.begin(), v1.end());
	myPrintVec(v1);

	v1.clear();
	myPrintVec(v1);
}

//数据存取
void test4()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrintVec(v1);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素：" << v1.front() << endl;
	cout << "最后一个元素：" << v1.back() << endl;
}

//互换容器
void test5()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrintVec(v1);
	vector<int>v2;
	for (int i = 30; i < 40; i++)
	{
		v2.push_back(i);
	}
	myPrintVec(v2);

	v1.swap(v2);
	myPrintVec(v1);
	myPrintVec(v2);
}



//预留空间
void test6()
{
	vector<int>v1;
	//利用reserve预先开辟空间
	v1.reserve(100000);

	int num = 0; //统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << "这是看容器扩容了" << num << endl;

}

int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
    std::cout << "Hello World!\n";
}

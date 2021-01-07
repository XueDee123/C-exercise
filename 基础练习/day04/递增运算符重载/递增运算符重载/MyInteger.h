#pragma once
#include<iostream>
class MyInteger
{
	friend std::ostream& operator<<(std::ostream& cout, MyInteger p);
public:
	MyInteger():m_Num(0)
	{}

	//前置++ 返回引用为了一直对一个数据进行操作
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}

	//后置++
	//这个int是占位符 可以区分前置++与后置++
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_Num++;
		return temp;
	}
private:
	int m_Num;
};


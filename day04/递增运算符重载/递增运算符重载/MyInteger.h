#pragma once
#include<iostream>
class MyInteger
{
	friend std::ostream& operator<<(std::ostream& cout, MyInteger p);
public:
	MyInteger():m_Num(0)
	{}

	//ǰ��++ ��������Ϊ��һֱ��һ�����ݽ��в���
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}

	//����++
	//���int��ռλ�� ��������ǰ��++�����++
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_Num++;
		return temp;
	}
private:
	int m_Num;
};


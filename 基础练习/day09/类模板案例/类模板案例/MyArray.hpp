#pragma once
/*
* ʵ��һ��ͨ��������
* 1.���Զ����������Լ��Զ����������͵����ݽ��д洢
* 2.�������е����ݴ洢������
* 3.���캯���п��Դ������������
* 4.�ṩ��Ӧ�Ŀ��������Լ�operator=��ֹǳ����
* �ṩβ�巨��βɾ��������������ݽ������ɾ��
* ����ͨ���±�������
* ���Ի�ȡ�����е�ǰԪ�ظ�������������
*/
#define ADDNUM 10
#include<iostream>
template<class T1>
class MyArray
{
public:
	MyArray();
	MyArray(int n);
	MyArray(const MyArray& p);
	T1 operator[](int i)
	{
		return this->_data[i];
	}
	MyArray& operator=(const MyArray& p)
	{
		if (this->_data != NULL)
		{
			delete[]this->_data;
			this->_data = NULL;
		}
		this->_num = p._num;
		this->_index = p._index;
		this->_data = new T1[this->_num]{0};
		for (int i = 0; i < this->_index; i++)
		{
			this->_data[i] = p._data[i];
		}
		std::cout << "ִ����=����" << std::endl;
		return *this;
	}
	~MyArray();
	int getCount()
	{
		return _num;
	}
	int getIndex()
	{
		return _index;
	}
	void Add(const T1& t);
	void Remove();
private:
	T1* _data;
	int _num;
	int _index;
};

template<class T1>
inline MyArray<T1>::MyArray()
{
	_data = new T1[ADDNUM]{0};
	_num = ADDNUM;
	_index = 0;
	std::cout << "ִ�����޲ι���" << std::endl;
}

template<class T1>
inline MyArray<T1>::MyArray(int n)
{
	_data = new T1[n]{0};
	_num = n;
	_index = 0;
	std::cout << "ִ�����вι���" << std::endl;
}

template<class T1>
inline MyArray<T1>::MyArray(const MyArray& p)
{
	this->_num = p._num;
	this->_index = p._index;
	//���
	this->_data = new T1[this->_num]{0};
	//����ҲҪcopy����
	for (int i = 0; i < this->_index; i++)
	{
		this->_data[i] =p._data[i];
	}
	std::cout << "ִ���˿�������" << std::endl;
}

template<class T1>
inline MyArray<T1>::~MyArray()
{
	if (this->_data != NULL)
	{
		delete[]this->_data;
		this->_data = NULL;
	}
	this->_num = 0;
	this->_index = 0;
	std::cout << "ִ��������" << std::endl;
}

template<class T1>
inline void MyArray<T1>::Add(const T1& t)
{
	if (_index == _num)
	{
		std::cout << "����ǰ"<< _num << std::endl;
		_num = _num + 2*ADDNUM;
		T1* temp = this->_data;
		this->_data = new T1[_num]{0};
		for (int i = 0; i < _index; i++)
		{
			this->_data[i] =temp[i];
		}
		
		delete[]temp;
		temp = NULL;
		std::cout << "���ݺ�" << _num << std::endl;
	}
	this->_data[_index] = t;
	_index++;
}

template<class T1>
inline void MyArray<T1>::Remove()
{

	if (_index > 0)
	{
		
		_index--;
	}

	if ((_num - _index) >( 2 * ADDNUM))
	{
		std::cout << "����ǰ" << _num << std::endl;
		_num = _num - 2*ADDNUM;
		T1* temp = this->_data;
		this->_data = new T1[_num]{ 0 };
		for (int i = 0; i < _index; i++)
		{
			this->_data[i] = temp[i];
		}
		
		delete[]temp;
		temp = NULL;
		std::cout << "���ݺ�" << _num << std::endl;
	}
}


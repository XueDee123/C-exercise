#pragma once
/*
* 实现一个通用数组类
* 1.可以对内置类型以及自定义数据类型的数据进行存储
* 2.将数组中的数据存储到堆区
* 3.构造函数中可以传入数组的容量
* 4.提供对应的拷贝构造以及operator=防止浅拷贝
* 提供尾插法和尾删除对数组里的数据进行添加删除
* 可以通过下标来访问
* 可以获取数组中当前元素个数和数组容量
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
		std::cout << "执行了=操作" << std::endl;
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
	std::cout << "执行了无参构造" << std::endl;
}

template<class T1>
inline MyArray<T1>::MyArray(int n)
{
	_data = new T1[n]{0};
	_num = n;
	_index = 0;
	std::cout << "执行了有参构造" << std::endl;
}

template<class T1>
inline MyArray<T1>::MyArray(const MyArray& p)
{
	this->_num = p._num;
	this->_index = p._index;
	//深拷贝
	this->_data = new T1[this->_num]{0};
	//数据也要copy过来
	for (int i = 0; i < this->_index; i++)
	{
		this->_data[i] =p._data[i];
	}
	std::cout << "执行了拷贝构造" << std::endl;
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
	std::cout << "执行了析构" << std::endl;
}

template<class T1>
inline void MyArray<T1>::Add(const T1& t)
{
	if (_index == _num)
	{
		std::cout << "扩容前"<< _num << std::endl;
		_num = _num + 2*ADDNUM;
		T1* temp = this->_data;
		this->_data = new T1[_num]{0};
		for (int i = 0; i < _index; i++)
		{
			this->_data[i] =temp[i];
		}
		
		delete[]temp;
		temp = NULL;
		std::cout << "扩容后" << _num << std::endl;
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
		std::cout << "缩容前" << _num << std::endl;
		_num = _num - 2*ADDNUM;
		T1* temp = this->_data;
		this->_data = new T1[_num]{ 0 };
		for (int i = 0; i < _index; i++)
		{
			this->_data[i] = temp[i];
		}
		
		delete[]temp;
		temp = NULL;
		std::cout << "缩容后" << _num << std::endl;
	}
}


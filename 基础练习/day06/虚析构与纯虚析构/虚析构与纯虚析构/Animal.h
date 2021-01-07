#pragma once
#include<iostream>
class Animal
{
public:
	Animal()
	{
		std::cout << "Animal构造函数" << std::endl;
	}
	virtual void speak()=0;
	//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	/*virtual~Animal()
	{
		std::cout << "Animal析构函数" << std::endl;
	}*/

	//如果有纯析构，那么该类也是抽象类
	virtual ~Animal() = 0;//这是纯虚析构 需要声明也要实现
};


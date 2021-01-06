#pragma once
//这个类是抽象类
//无法实例化对象
//子类必须重写纯虚函数，不然也是抽象类
class Base
{
public:
	//纯虚函数
	virtual void func() = 0;
};


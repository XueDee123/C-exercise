#pragma once
#include "Base.h"
#include<iostream>
class Coffee :
    public Base
{
public:
	virtual void boilWater()
	{
		std::cout << "��ˮ" << std::endl;
	}
	virtual void brewing()
	{
		std::cout << "���ݿ���" << std::endl;
	}
	virtual void excipientsAdded()
	{
		std::cout << "���Ǻ�ţ��" << std::endl;
	}
	virtual void pourIntoCup()
	{
		std::cout << "���뱭��" << std::endl;
	}
};


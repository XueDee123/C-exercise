#pragma once
#include "Base.h"
#include<iostream>
class Coffee :
    public Base
{
public:
	virtual void boilWater()
	{
		std::cout << "ÖóË®" << std::endl;
	}
	virtual void brewing()
	{
		std::cout << "³åÅÝ¿§·È" << std::endl;
	}
	virtual void excipientsAdded()
	{
		std::cout << "¼ÓÌÇºÍÅ£ÄÌ" << std::endl;
	}
	virtual void pourIntoCup()
	{
		std::cout << "µ¹Èë±­ÖÐ" << std::endl;
	}
};


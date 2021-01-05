#pragma once
#include "Building.h"
#include <iostream>
class GoodGay
{
public:
	Building* b;
public:
	GoodGay()
	{
		b = new Building;
	}
	GoodGay(const GoodGay&p)
	{
		b = new Building;
	}
	void visit();
	~GoodGay()
	{
		delete b;
		b = NULL;
	}
};


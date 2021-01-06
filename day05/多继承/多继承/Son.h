#pragma once
#include "Base1.h"
#include "Base2.h"
class Son :    public Base1,public Base2
{
public:
	Son():c(300),d(400)
	{}
	int c;
	int d;

};


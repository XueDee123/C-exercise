#pragma once
#include "CPU.h"
#include<iostream>
#include "GraphicsCard.h"
#include"MemoryModule.h"
#include<string>
class Computer
{
public:
	void doWork(CPU* c, GraphicsCard* g, MemoryModule* m)
	{
		c->calculation();
		g->Display();
		m->Storage();
	}
};


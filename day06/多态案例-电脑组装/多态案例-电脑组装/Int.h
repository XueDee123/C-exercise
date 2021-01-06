#pragma once
#include "CPU.h"
#include<iostream>
#include "GraphicsCard.h"
#include"MemoryModule.h"
#include<string>
class Int :
    public CPU, 
    public GraphicsCard,
    public MemoryModule
{
public :
    Int():name("英特尔")
    {}
    virtual void calculation()
    {
        std::cout << name << "CPU执行计算" << std::endl;
    }
    virtual void Display()
    {
        std::cout << name << "显卡执行显示" << std::endl;
    }
    virtual void Storage()
    {
        std::cout << name << "内存条执行存储" << std::endl;
    }
    std::string name;
};


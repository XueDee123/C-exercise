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
    Int():name("Ӣ�ض�")
    {}
    virtual void calculation()
    {
        std::cout << name << "CPUִ�м���" << std::endl;
    }
    virtual void Display()
    {
        std::cout << name << "�Կ�ִ����ʾ" << std::endl;
    }
    virtual void Storage()
    {
        std::cout << name << "�ڴ���ִ�д洢" << std::endl;
    }
    std::string name;
};


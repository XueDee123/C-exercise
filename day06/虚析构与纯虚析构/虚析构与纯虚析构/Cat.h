#pragma once
#include "Animal.h"
#include<iostream>
#include <string>
class Cat :
    public Animal
{
public :
    Cat(std::string n)
    {
        name = new std::string(n);
        std::cout << "Cat构造函数" << std::endl;
    }
    void speak()
    {
        std::cout<<*name << "-->喵喵" << std::endl;
    }
    ~Cat()
    {
        if (name != NULL)
        {
            delete name;
            name = NULL;
            
        }
        std::cout << "执行cat析构" << std::endl;
    }
    std::string* name;
};


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
        std::cout << "Cat���캯��" << std::endl;
    }
    void speak()
    {
        std::cout<<*name << "-->����" << std::endl;
    }
    ~Cat()
    {
        if (name != NULL)
        {
            delete name;
            name = NULL;
            
        }
        std::cout << "ִ��cat����" << std::endl;
    }
    std::string* name;
};


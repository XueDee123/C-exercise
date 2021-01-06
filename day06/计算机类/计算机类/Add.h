#pragma once
#include "BaseCalculator.h"
class Add :
    public BaseCalculator
{
public:
    Add(int a,int b):BaseCalculator(a,b)
    {}
    int getRes()
    {
        return n1 + n2;
    }
};


#pragma once
#include "Staff.h"
class Boss :
    public Staff
{
public:
    Boss(int a, std::string name, int did)
    {
        this->_no = a;
        this->_name = name;
        this->_deptId = did;
    }
    virtual void showInfo();
    virtual std::string getDeptName();
   
   
};


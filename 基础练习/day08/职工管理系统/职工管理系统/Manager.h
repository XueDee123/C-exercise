#pragma once
#include "Staff.h"
class Manager :
    public Staff
{
public:
    Manager(int a, std::string name, int did)
    {
        this->_no = a;
        this->_name = name;
        this->_deptId = did;
    }
    virtual void showInfo();
    virtual std::string getDeptName();
    
};


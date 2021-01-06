#include "Boss.h"

void Boss::showInfo()
{
	std::cout << "职工编号:"
		<< this->_no
		<< "\t姓名"
		<< this->_name
		<< "\t岗位"
		<< this->getDeptName()
		<< "\t岗位职责：管理公司所有事务"
		<< std::endl;
}

std::string Boss::getDeptName()
{
	return "老板";
}

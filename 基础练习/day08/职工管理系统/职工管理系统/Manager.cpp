#include "Manager.h"

void Manager::showInfo()
{
	std::cout << "职工编号:"
		<< this->_no
		<< "\t姓名"
		<< this->_name
		<< "\t岗位"
		<< this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工"
		<< std::endl;
}

std::string Manager::getDeptName()
{
	return "经理";
}

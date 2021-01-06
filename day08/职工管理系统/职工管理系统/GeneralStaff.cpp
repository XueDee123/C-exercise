#include "GeneralStaff.h"

void GeneralStaff::showInfo()
{
	std::cout << "职工编号:"
		<< this->_no
		<< "\t姓名"
		<< this->_name
		<< "\t岗位"
		<< this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务"
		<< std::endl;
}

std::string GeneralStaff::getDeptName()
{
	return "普通员工";
}

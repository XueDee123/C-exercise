#include "Manager.h"

void Manager::showInfo()
{
	std::cout << "ְ�����:"
		<< this->_no
		<< "\t����"
		<< this->_name
		<< "\t��λ"
		<< this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��"
		<< std::endl;
}

std::string Manager::getDeptName()
{
	return "����";
}

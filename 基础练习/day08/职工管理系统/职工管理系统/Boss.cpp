#include "Boss.h"

void Boss::showInfo()
{
	std::cout << "ְ�����:"
		<< this->_no
		<< "\t����"
		<< this->_name
		<< "\t��λ"
		<< this->getDeptName()
		<< "\t��λְ�𣺹���˾��������"
		<< std::endl;
}

std::string Boss::getDeptName()
{
	return "�ϰ�";
}

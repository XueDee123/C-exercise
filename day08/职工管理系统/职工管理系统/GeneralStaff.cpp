#include "GeneralStaff.h"

void GeneralStaff::showInfo()
{
	std::cout << "ְ�����:"
		<< this->_no
		<< "\t����"
		<< this->_name
		<< "\t��λ"
		<< this->getDeptName()
		<< "\t��λְ����ɾ�����������"
		<< std::endl;
}

std::string GeneralStaff::getDeptName()
{
	return "��ͨԱ��";
}

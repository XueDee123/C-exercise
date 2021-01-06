#include "ManagerSys.h"

ManagerSys::ManagerSys()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "文件不存在" << std::endl;
		_work_num = 0;
		_work = NULL;
		fileEmpty = true;
		ifs.close();
		return;
	}
	//文件存在没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "文件为空" << std::endl;
		_work_num = 0;
		_work = NULL;
		fileEmpty = true;
		ifs.close();
		return;
	}
	_work_num = getWorkNum();
	_work = new Staff * [_work_num];
	initWork();
}

ManagerSys::~ManagerSys()
{
	if (_work != NULL)
	{
		for (int i = 0; i < _work_num; i++)
		{
			if (_work[i] != NULL)
			{
				delete _work[i];
			}
		}
		delete[] _work;
		_work = NULL;
	}
}

int ManagerSys::showMenu()
{
	std::cout << "******************************" << std::endl;
	std::cout << "*******欢迎使用职工管理系统*****" << std::endl;
	std::cout << "*********0.退出管理系统********" << std::endl;
	std::cout << "*********1.增加职工信息********" << std::endl;
	std::cout << "*********2.显示职工信息********" << std::endl;
	std::cout << "*********3.删除离职职工********" << std::endl;
	std::cout << "*********4.修改职工信息********" << std::endl;
	std::cout << "*********5.查找职工信息********" << std::endl;
	std::cout << "*********6.排序职工信息********" << std::endl;
	std::cout << "*********7.清空所有文档********" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << std::endl;
	std::cout << "请输入您的选择:";
	int ret = 0;
	std::cin >> ret;
	return ret;
}

void ManagerSys::add()
{
	std::cout << "请输入添加员工数量:";
	int num = 0;
	std::cin >> num;
	if (num > 0)
	{
		int newSize = this->_work_num + num;
		Staff**temp= new Staff* [newSize];
		if (_work != NULL)
		{
			for (int i = 0; i < this->_work_num; i++)
			{
				temp[i] = this->_work[i];
			}
		}
		for (int i = 0; i < num; i++)
		{
			int id, stpId;
			std::string nam;
			std::cout << "请输入" << i + 1 << "个员工的编号:";
			std::cin >> id;
			std::cout << "请输入" << i + 1 << "个员工的姓名:";
			std::cin >> nam;

			std::cout << "请选择员工岗位:";
			std::cout << "1、普通员工;";
			std::cout << "2、经理;";
			std::cout << "3、老板;";
			std::cin >> stpId;
			Staff* p = NULL;
			switch (stpId)
			{
			case 1:
				p = new GeneralStaff(id, nam, stpId);
				break;
			case 2:
				p = new Manager(id, nam, stpId);
				break;
			case 3:
				p = new Boss(id, nam, stpId);
				break;
			default:
				break;
			}

			temp[this->_work_num + i] = p;
		}
		if (_work != NULL)
		{
			delete[] _work;
			_work = NULL;
		}
		_work = temp;
		_work_num = newSize;
		save();
		fileEmpty = false;
		std::cout << "成功添加" << num << "员工" << std::endl;
	}
	else
	{
		std::cout << "输入有误" << std::endl;
	}
	system("pause");
	system("cls");
}



void ManagerSys::exitSys()
{
	std::cout << "感谢使用" << std::endl;
	exit(0);
}

void ManagerSys::updata()
{
	if (fileEmpty)
	{
		std::cout << "文件不存在或记录为空" << std::endl;
		return;
	}
	std::cout << "请输入要修改的员工编号:";
	int n = 0;
	std::cin >> n;
	int ret = isExist(n);
	if (ret != -1)
	{
		std::cout << "请输入员工的姓名:";
		std::cin >> _work[ret]->_name;
		
		std::cout << "请选择员工岗位:";
		std::cout << "1、普通员工;";
		std::cout << "2、经理;";
		std::cout << "3、老板;";
		std::cin >> _work[ret]->_deptId;
		Staff* p = NULL;
		switch (_work[ret]->_deptId)
		{
		case 1:
			p = new GeneralStaff(_work[ret]->_no, _work[ret]->_name, _work[ret]->_deptId);
			break;
		case 2:
			p = new Manager(_work[ret]->_no, _work[ret]->_name, _work[ret]->_deptId);
			break;
		case 3:
			p = new Boss(_work[ret]->_no, _work[ret]->_name, _work[ret]->_deptId);
			break;
		default:
			break;
		}
		if (p != NULL)
		{
			Staff* tp = _work[ret];
			_work[ret] = p;
			delete tp;

			this->save();
			std::cout << "修改成功" << std::endl;
		}
		
	}
	else
	{
		std::cout << "没有找到数据" << std::endl;
	}
	system("pause");
	system("cls");
}

void ManagerSys::find()
{
	if (fileEmpty)
	{
		std::cout << "文件不存在或记录为空" << std::endl;
		return;
	}
	std::cout << "请输入要查找的员工编号:";
	int n = 0;
	std::cin >> n;
	int ret = isExist(n);
	if (ret != -1)
	{
		_work[ret]->showInfo();
	}
	else
	{
		std::cout << "没有找到数据" << std::endl;
	}
	system("pause");
	system("cls");
}

void ManagerSys::clear()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::trunc);
	ofs.close();
	if (this->_work != NULL)
	{
		for (int i = 0; i < _work_num; i++)
		{
			if (_work[i] != NULL)
			{
				delete _work[i];
				_work[i] = NULL;
			}
			
		}
		_work_num = 0;
		delete[] _work;
		_work = NULL;
		fileEmpty = true;
	}
	std::cout << "清空成功" << std::endl;
}

void ManagerSys::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);
	for (int i = 0; i < _work_num; i++)
	{
		ofs << _work[i]->_no << " "
			<< _work[i]->_name << " "
			<< _work[i]->_deptId << std::endl;
	}
	ofs.close();
}

int ManagerSys::getWorkNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string nam;
	int pid;
	int num = 0;
	while (ifs>>id&&ifs>>nam&&ifs>>pid)
	{
		num++;
	}
	ifs.close();
	return num;
}

void ManagerSys::initWork()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string nam;
	int pid;
	int index=0;
	while (ifs >> id && ifs >> nam && ifs >> pid)
	{
		Staff* p = NULL;
		if (pid == 1)
		{
			p = new GeneralStaff(id, nam, pid);
		}
		else if (pid == 2)
		{
			p = new Manager(id, nam, pid);
		}
		else if (pid == 3)
		{
			p = new Boss(id, nam, pid);
		}
		this->_work[index] = p;
		index++;
	}
	ifs.close();
}

int ManagerSys::isExist(int id)
{
	for (int i = 0; i < _work_num; i++)
	{
		if (id == this->_work[i]->_no)
		{
			return i;
		}
	}
	return -1;
}

void ManagerSys::showAll()
{
	if (fileEmpty)
	{
		std::cout << "文件不存在或记录为空" << std::endl;
	}
	else
	{
		for (int i = 0; i < _work_num; i++)
		{
			this->_work[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void ManagerSys::del()
{
	if (fileEmpty)
	{
		std::cout << "文件不存在或记录为空" << std::endl;
		return;
	}
	std::cout << "请输入离职员工编号:";
	int n = 0;
	std::cin >> n;
	int ret = isExist(n);
	if (ret != -1)
	{
		for (int i = ret; i < _work_num-1; i++)
		{
			_work[i] = _work[i + 1];
		}
		_work_num--;
		this->save();
		std::cout << "删除成功" << std::endl;
	}
	else
	{
		std::cout << "没有找到数据" << std::endl;
	}
	system("pause");
	system("cls");
}

std::vector<std::string> ManagerSys::split(const std::string& str, const std::string& pattern)
{
	std::vector<std::string> res;
	if (str == "")
		return res;
	//在字符串末尾也加入分隔符，方便截取最后一段
	std::string strs = str + pattern;
	size_t pos = strs.find(pattern);

	while (pos != strs.npos)
	{
		std::string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(pattern);
	}

	return res;
}
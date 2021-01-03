

#include "AddressBook.h"
int sel(addbook* ab, std::string name);
void init(addbook* ab)
{
	ab->current = 0;
	memset(ab->cons, 0, sizeof(ab->cons));
	std::cout << "数据初始化成功" << std::endl;
}

void add(addbook* ab)
{
	
	if (ab->current >= MaxContacts)
	{
		std::cout << "联系人个数已经到达上限" << std::endl;
		return;
	}
	std::cout << "-----------添加用户---------------" << std::endl;
	std::cout << "请输入姓名：";
	std::cin >> ab->cons[ab->current].name;
	std::cout << "请输入年龄：";
	std::cin >> ab->cons[ab->current].age;
	std::cout << "请输入性别：";
	std::cin >> ab->cons[ab->current].sex;
	std::cout << "请输入电话：";
	std::cin >> ab->cons[ab->current].tel;
	std::cout << "请输入家庭住址：";
	std::cin >> ab->cons[ab->current].address;
	ab->current++;
	std::cout << "联系人添加成功"<<std::endl;
}

void display(addbook* ab)
{
	std::cout << "-----------显示用户---------------" << std::endl;
	std::cout << "\t姓名" << "\t性别" << "\t年龄" << "\t\t电话" << "\t\t地址" << std::endl;
	for (int i = 0; i <ab->current; i++)
	{
		std::cout << "\t"<<ab->cons[i].name
			<< "\t"<< ab->cons[i].sex
			<< "\t"<< ab->cons[i].age
			<< "\t"<< ab->cons[i].tel
			<< "\t\t"<< ab->cons[i].address
			<< "\t\t"<< std::endl;
	}
}

void del(addbook* ab)
{
	std::cout << "-------请输入要删除用户姓名---------" << std::endl;
	std::string name;
	std::cin >> name;
	int index=sel(ab, name);
	if (index == -1)
	{
		std::cout << "未找到该联系人" << std::endl;
		return;
	}
	for (int i = index; i < ab->current - 1; i++)
	{
		ab->cons[i] = ab->cons[i+1];
	}
	ab->current--;
	std::cout << "删除数据成功" << std::endl;
}

int sel(addbook* ab,std::string name)
{
	for (int i = 0; i < ab->current; i++)
	{
		if (name.compare(ab->cons[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void select(addbook* ab)
{
	std::cout << "-------请输入要查找用户姓名---------" << std::endl;
	std::string name;
	std::cin >> name;
	int index = sel(ab, name);
	if (index == -1)
	{
		std::cout << "未找到该联系人" << std::endl;
		return;
	}
	std::cout << "\t姓名" << "\t性别" << "\t年龄" << "\t\t电话" << "\t\t地址" << std::endl;
	
		std::cout << "\t" << ab->cons[index].name
			<< "\t" << ab->cons[index].sex
			<< "\t" << ab->cons[index].age
			<< "\t" << ab->cons[index].tel
			<< "\t\t" << ab->cons[index].address
			<< "\t\t" << std::endl;
	
}

void update(addbook* ab)
{
	std::cout << "-------请输入要修改用户姓名---------" << std::endl;
	std::string name;
	std::cin >> name;
	int index = sel(ab, name);
	if (index == -1)
	{
		std::cout << "未找到该联系人" << std::endl;
		return;
	}
	std::cout << "请修改姓名：";
	std::cin >> ab->cons[index].name;
	std::cout << "请修改年龄：";
	std::cin >> ab->cons[index].age;
	std::cout << "请修改性别：";
	std::cin >> ab->cons[index].sex;
	std::cout << "请修改电话：";
	std::cin >> ab->cons[index].tel;
	std::cout << "请修改家庭住址：";
	std::cin >> ab->cons[index].address;
	
	std::cout << "联系人修改成功" << std::endl;
}

void clear(addbook* ab)
{
	ab->current = 0;
	memset(ab->cons, 0, sizeof(ab->cons));
	std::cout << "数据清空成功" << std::endl;
}
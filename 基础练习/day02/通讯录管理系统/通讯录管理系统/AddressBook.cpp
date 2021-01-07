

#include "AddressBook.h"
int sel(addbook* ab, std::string name);
void init(addbook* ab)
{
	ab->current = 0;
	memset(ab->cons, 0, sizeof(ab->cons));
	std::cout << "���ݳ�ʼ���ɹ�" << std::endl;
}

void add(addbook* ab)
{
	
	if (ab->current >= MaxContacts)
	{
		std::cout << "��ϵ�˸����Ѿ���������" << std::endl;
		return;
	}
	std::cout << "-----------����û�---------------" << std::endl;
	std::cout << "������������";
	std::cin >> ab->cons[ab->current].name;
	std::cout << "���������䣺";
	std::cin >> ab->cons[ab->current].age;
	std::cout << "�������Ա�";
	std::cin >> ab->cons[ab->current].sex;
	std::cout << "������绰��";
	std::cin >> ab->cons[ab->current].tel;
	std::cout << "�������ͥסַ��";
	std::cin >> ab->cons[ab->current].address;
	ab->current++;
	std::cout << "��ϵ����ӳɹ�"<<std::endl;
}

void display(addbook* ab)
{
	std::cout << "-----------��ʾ�û�---------------" << std::endl;
	std::cout << "\t����" << "\t�Ա�" << "\t����" << "\t\t�绰" << "\t\t��ַ" << std::endl;
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
	std::cout << "-------������Ҫɾ���û�����---------" << std::endl;
	std::string name;
	std::cin >> name;
	int index=sel(ab, name);
	if (index == -1)
	{
		std::cout << "δ�ҵ�����ϵ��" << std::endl;
		return;
	}
	for (int i = index; i < ab->current - 1; i++)
	{
		ab->cons[i] = ab->cons[i+1];
	}
	ab->current--;
	std::cout << "ɾ�����ݳɹ�" << std::endl;
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
	std::cout << "-------������Ҫ�����û�����---------" << std::endl;
	std::string name;
	std::cin >> name;
	int index = sel(ab, name);
	if (index == -1)
	{
		std::cout << "δ�ҵ�����ϵ��" << std::endl;
		return;
	}
	std::cout << "\t����" << "\t�Ա�" << "\t����" << "\t\t�绰" << "\t\t��ַ" << std::endl;
	
		std::cout << "\t" << ab->cons[index].name
			<< "\t" << ab->cons[index].sex
			<< "\t" << ab->cons[index].age
			<< "\t" << ab->cons[index].tel
			<< "\t\t" << ab->cons[index].address
			<< "\t\t" << std::endl;
	
}

void update(addbook* ab)
{
	std::cout << "-------������Ҫ�޸��û�����---------" << std::endl;
	std::string name;
	std::cin >> name;
	int index = sel(ab, name);
	if (index == -1)
	{
		std::cout << "δ�ҵ�����ϵ��" << std::endl;
		return;
	}
	std::cout << "���޸�������";
	std::cin >> ab->cons[index].name;
	std::cout << "���޸����䣺";
	std::cin >> ab->cons[index].age;
	std::cout << "���޸��Ա�";
	std::cin >> ab->cons[index].sex;
	std::cout << "���޸ĵ绰��";
	std::cin >> ab->cons[index].tel;
	std::cout << "���޸ļ�ͥסַ��";
	std::cin >> ab->cons[index].address;
	
	std::cout << "��ϵ���޸ĳɹ�" << std::endl;
}

void clear(addbook* ab)
{
	ab->current = 0;
	memset(ab->cons, 0, sizeof(ab->cons));
	std::cout << "������ճɹ�" << std::endl;
}
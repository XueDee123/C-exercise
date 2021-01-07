
#include <iostream>
#include"ManagerSys.h"



void test()
{
	ManagerSys* p = new ManagerSys;
	int ret = 0;
	do
	{
		ret = p->showMenu();
		switch (ret)
		{
		case 0:
			p->exitSys();
			break;
		case 1:
			p->add();
			break;
		case 2:
			p->showAll();
			break;
		case 3:
			p->del();
			break;
		case 4:
			p->updata();
			break;
		case 5:
			p->find();
			break;
		case 6:
			
			break;
		case 7:
			p->clear();
			break;
		default:
			system("cls");
			break;
		}
	} while (ret);
	delete p;
	p = NULL;
}


int main()
{
	test();
	std::cout << "Hello World!\n";
}


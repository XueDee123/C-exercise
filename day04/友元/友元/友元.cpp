

#include <iostream>
#include "Building.h"
#include "GoodGay.h"

void goodGay(const Building* b)
{
	std::cout << "goodGay访问" << b->sitting_room << std::endl;
	std::cout << "goodGay访问" << b->bed_room << std::endl;
}

void test()
{
	Building b;
	goodGay(&b);
}

void test1()
{
	GoodGay g;
	g.visit();
}

int main()
{
	test();
	test1();
    std::cout << "Hello World!\n";
}



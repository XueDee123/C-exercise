#pragma once
#include<string>
class Building
{

	friend void goodGay(const Building* b);
	friend class GoodGay;
public:
	std::string sitting_room;
private:
	std::string bed_room;
public:
	Building():sitting_room("¿ÍÌü"),bed_room("ÎÔÊÒ")
	{}
};


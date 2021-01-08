

#include <iostream>
#include <vector>

/*
* 容器嵌套容器
*/

void test()
{
    std::vector<std::vector<int>>v = { {1,2,3},{4,5,6} };
	for (std::vector<std::vector<int>>::iterator i = v.begin(); i !=v.end(); i++)
	{
		for (std::vector<int>::iterator j = (*i).begin(); j!= (*i).end(); j++)
		{
			std::cout << *j << std::endl;
		}
	}

}


int main()
{
	test();
    std::cout << "Hello World!\n";
}


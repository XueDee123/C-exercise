// 乘法口诀表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			std::cout << j<<"*"<<i<<"="<<j*i<<" ";
		}
		std::cout<<std::endl;
	}


    std::cout << "Hello World!\n";
}



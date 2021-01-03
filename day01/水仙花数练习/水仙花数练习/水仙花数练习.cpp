// 水仙花数练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


/*
* 水仙花数是指一个3位数，它的每个位上的数字的3次幂之和等于它本身
* 例如：1^3+5^3+3^3=153
* 请利用do..while语句，求出所有3位数中的水仙花数
*/

#include <iostream>
#include<cmath>
#include <Windows.h>


int main()
{
	int i = 100;
    //将所有的三位数进行输出
	for ( i = 100; i < 999; i++)
	{
		std::cout << i << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	i = 100;
	do {
		int _hundred, _ten, _one;
		_hundred = i / 100 == 0 ? 0 : pow(i / 100, 3);
		_ten =(i/10)%10==0?0: pow((i / 10) % 10, 3);
		_one = i%10 == 0 ? 0 : pow(i % 10, 3);
		if (_hundred + _ten + _one == i)std::cout << i << std::endl;
		i++;
	} while (i < 1000);


    std::cout << "Hello World!\n";
}


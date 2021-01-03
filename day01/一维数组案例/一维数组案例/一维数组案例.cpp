// 一维数组案例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/*
* 案例：五只小猪称体重
* 在一个数组中记录了五只小猪的体重，如：int arr[5]={300,350,200,400,250};
* 找出并打印最重小猪体重
*/
void test()
{
    int arr[5] = { 300,350,200,400,250 };
	int max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (max < arr[i])max = arr[i];
	}
	std::cout << max << std::endl;
}

/*
* 数组元素逆置
* 请声明一个5个元素的数组，并且将元素逆置
* 如原数组为 1,3,2,5,4  逆序成4,5,2,3,1
*/
void test1()
{
	int arr[5] = { 1,3,2,5,4 };
	
	for (int i = 0, j = sizeof(arr)/sizeof(arr[0])-1; i < j; i++,j--)
	{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
	}
	for (int n = 0; n < sizeof(arr) / sizeof(arr[0]); n++)
	{
		std::cout << arr[n] << std::endl;
	}
	
}

/*
* 冒泡排序
* 4,2,8,0,5,7,1,3,9
*/
void test02()
{
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0])-1; i++)
	{
		for (int j =0 ; j < sizeof(arr) / sizeof(arr[0]) - i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
int main()
{
	//test();
	//test1();
	test02();
    std::cout << "Hello World!\n";
}


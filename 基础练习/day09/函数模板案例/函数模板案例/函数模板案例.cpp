

#include <iostream>

/*
* 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
* 排序规则从大到小，排序算法为选择排序
* 分别利用char数组和int数组进行测试
*/

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T *t,int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (*(t+j) < *(t + j+1))
			{
				mySwap<T>(*(t + j), *(t + j + 1));
			}
		}
	}
}

void test()
{
	int a[] = { 2,6,4,8,9,1 };
	mySort<int>(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}



template<typename T>
void mySort1(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap<T>(arr[max], arr[i]);
		}
	}
}

void test1()
{
	int a[] = { 2,6,4,8,9,1 };
	mySort1<int>(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		std::cout << a[i] << " " ;
	}
	std::cout << std::endl;
}

int main()
{
	test();
	test1();
    std::cout << "Hello World!\n";
}


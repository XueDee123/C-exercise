#pragma once
#include<iostream>
class Animal
{
public:
	Animal()
	{
		std::cout << "Animal���캯��" << std::endl;
	}
	virtual void speak()=0;
	//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
	/*virtual~Animal()
	{
		std::cout << "Animal��������" << std::endl;
	}*/

	//����д���������ô����Ҳ�ǳ�����
	virtual ~Animal() = 0;//���Ǵ������� ��Ҫ����ҲҪʵ��
};




//�������Ա���windows.h��socket2.h�ĺ��ͻ
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<WinSock2.h>


//��winƽ̨����Ҫ������ļ���ȻWSAStartup�ᱨ��
//#pragma comment(lib,"ws2_32.lib")
//��Ȼ�����һ�����-��������-������-������������



int main()
{
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	//����socket
	WSAStartup(ver, &data);



	//���windows socket����
	WSACleanup();

	return 0;
}
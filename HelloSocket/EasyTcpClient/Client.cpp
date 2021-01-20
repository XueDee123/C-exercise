

//�������Ա���windows.h��socket2.h�ĺ��ͻ
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<WinSock2.h>
#include <stdio.h>

//��winƽ̨����Ҫ������ļ���ȻWSAStartup�ᱨ��
//#pragma comment(lib,"ws2_32.lib")
//��Ȼ�����һ�����-��������-������-������������

enum CMD
{
	CMD_LOGIN,
	CMD_LOGOUT,
	CMD_ERROR
};
struct DataHeader {
	short dataLen;
	short cmd;
};
struct Login {
	char userName[32];
	char password[32];
};
struct  LoginResult
{
	int result;
};
struct Logout
{
	char userName[32];
};
struct  LogoutResult
{
	int result;
};

int main()
{
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	//����socket
	WSAStartup(ver, &data);
	//1.����һ��socket
	SOCKET _sock= socket(AF_INET,SOCK_STREAM,0);
	if (_sock == INVALID_SOCKET)
	{
		printf("�����׽���ʧ��");
	}
	else
	{
		printf("�����׽��ֳɹ�");
	}
	//2.���ӷ�����
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int ret=connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (ret == SOCKET_ERROR)
	{
		printf("���ӷ�����ʧ��");
	}
	else
	{
		printf("���ӷ������ɹ�");
	}
	
	
	while (true)
	{
		//3.����������Ϣ
		char cmdBuf[1024] = {};
		scanf("%s", &cmdBuf);
		//4.��������
		if (0 == strcmp(cmdBuf, "exit"))
		{
			break;
		}
		else if (0 == strcmp(cmdBuf, "login"))
		{
			Login login = { "tom","tom" };
			DataHeader dh = {sizeof(Login),CMD_LOGIN };
			send(_sock, (char*)&dh, sizeof(DataHeader), 0);
			send(_sock, (char*)&login, sizeof(Login), 0);

			DataHeader retHeader = {};
			LoginResult retLogin = {};
			recv(_sock, (char*)&retHeader, sizeof(DataHeader), 0);
			recv(_sock, (char*)&retLogin, sizeof(LoginResult), 0);
			printf("LoginResult %d\n", retLogin.result);
		}
		else if (0 == strcmp(cmdBuf, "logout"))
		{
			Logout logout = {};
			DataHeader dh = {sizeof(Logout) , CMD_LOGOUT };
			send(_sock, (char*)&dh, sizeof(DataHeader), 0);
			send(_sock, (char*)&logout, sizeof(Logout), 0);

			DataHeader retHeader = {};
			LogoutResult retLogout = {};
			recv(_sock, (char*)&retHeader, sizeof(DataHeader), 0);
			recv(_sock, (char*)&retLogout, sizeof(LogoutResult), 0);
			printf("LogoutResult %d\n", retLogout.result);
		}
		else
		{
			printf("��֧�ֵ�����\n");
		}
	
	}
	
	//7.�ر��׽���

	closesocket(_sock);
	//���windows socket����
	WSACleanup();
	printf("���˳�");
	getchar();
	return 0;
}
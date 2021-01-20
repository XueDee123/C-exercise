#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>

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
	WSAStartup(ver, &data);
	//----------------
	//1.����һ��socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//2.�󶨶˿�
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; //inet_addr("127.0.0.1");
	if (bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR)
	{
		printf("����,�����ڽ��տͻ��˵�����˿�ʧ��\n");

	}
	else
	{
		printf("�����ڽ��տͻ��˵�����˿ڳɹ�..\n");
	}
	//3.�����˿�
	if (listen(_sock, 5) == SOCKET_ERROR)
	{
		printf("����,��������˿�ʧ��\n");
	}
	else
	{
		printf("��������˿ڳɹ�..\n");
	}
	//4.�ȴ��ͻ�������
	sockaddr_in _client = {};
	int nAddrLen = sizeof(_client);
	SOCKET _clientSock = INVALID_SOCKET;
	_clientSock = accept(_sock, (sockaddr*)&_client, &nAddrLen);
	if (_clientSock == INVALID_SOCKET)
	{
		printf("����,���յ���Ч�ͻ���socket\n");
	}
	printf("�¿ͻ��˼��룬IP=%s \n", inet_ntoa(_client.sin_addr));


	while (true)
	{
		DataHeader header = {};

		//���տͻ��˵���������
		int ret = recv(_clientSock, (char*)&header, sizeof(DataHeader), 0);
		if (ret <= 0)
		{
			printf("�ͻ����˳���������� \n");
			break;
		}
		printf("�յ�����:%d ,����%d\n", header.dataLen, header.cmd);

		switch (header.cmd)
		{
			case CMD_LOGIN:
			{
				Login login = {};
				recv(_clientSock, (char*)&login, sizeof(Login), 0);

				LoginResult rest = { 1 };
				send(_clientSock, (char*)&header, sizeof(DataHeader), 0);
				send(_clientSock, (char*)&rest, sizeof(LoginResult), 0);
			}
			break;
			case CMD_LOGOUT:
			{
				Logout logout = {};
				recv(_clientSock, (char*)&logout, sizeof(Logout), 0);

				LogoutResult rest = { 1 };
				send(_clientSock, (char*)&header, sizeof(DataHeader), 0);
				send(_clientSock, (char*)&rest, sizeof(LogoutResult), 0);
			}
			break;
			default:
			{
				header.cmd = CMD_ERROR;
				header.dataLen = 0;
				send(_clientSock, (char*)&header, sizeof(DataHeader), 0);
			}
			break;
		}
	}

	//8.�ر��׽���
	closesocket(_sock);
	//������
	WSACleanup();
	printf("���˳�");
	getchar();
	return 0;
}
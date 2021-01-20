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
	//1.建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//2.绑定端口
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; //inet_addr("127.0.0.1");
	if (bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR)
	{
		printf("错误,绑定用于接收客户端的网络端口失败\n");

	}
	else
	{
		printf("绑定用于接收客户端的网络端口成功..\n");
	}
	//3.监听端口
	if (listen(_sock, 5) == SOCKET_ERROR)
	{
		printf("错误,监听网络端口失败\n");
	}
	else
	{
		printf("监听网络端口成功..\n");
	}
	//4.等待客户端连接
	sockaddr_in _client = {};
	int nAddrLen = sizeof(_client);
	SOCKET _clientSock = INVALID_SOCKET;
	_clientSock = accept(_sock, (sockaddr*)&_client, &nAddrLen);
	if (_clientSock == INVALID_SOCKET)
	{
		printf("错误,接收到无效客户端socket\n");
	}
	printf("新客户端加入，IP=%s \n", inet_ntoa(_client.sin_addr));


	while (true)
	{
		DataHeader header = {};

		//接收客户端的请求数据
		int ret = recv(_clientSock, (char*)&header, sizeof(DataHeader), 0);
		if (ret <= 0)
		{
			printf("客户端退出，任务结束 \n");
			break;
		}
		printf("收到数据:%d ,命令%d\n", header.dataLen, header.cmd);

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

	//8.关闭套接字
	closesocket(_sock);
	//清理环境
	WSACleanup();
	printf("已退出");
	getchar();
	return 0;
}
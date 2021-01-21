#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>
#include <vector>
using namespace std;

enum CMD
{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_NEW_USER_JOIN,
	CMD_ERROR
};
struct DataHeader {
	short dataLen;
	short cmd;
};
struct Login :public DataHeader
{
	Login()
	{
		dataLen = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char userName[32];
	char password[32];
};
struct  LoginResult :public DataHeader
{
	LoginResult()
	{
		dataLen = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
		result = 1;
	}
	int result;
};
struct Logout :public DataHeader
{
	Logout()
	{
		dataLen = sizeof(Logout);
		cmd = CMD_LOGOUT;
	}
	char userName[32];
};
struct  LogoutResult :public DataHeader
{
	LogoutResult()
	{
		dataLen = sizeof(LogoutResult);
		cmd = CMD_LOGOUT_RESULT;
		result = 1;
	}
	int result;
};
struct  NewUserJoin :public DataHeader
{
	NewUserJoin()
	{
		dataLen = sizeof(NewUserJoin);
		cmd = CMD_NEW_USER_JOIN;		
		scok = 0;
	}
	int scok;
};

vector<SOCKET>g_clients;
int processor(SOCKET _clientSock)
{
	//缓冲区
	char szRecv[1024] = {};
	//接收客户端的请求数据
	int ret = recv(_clientSock, szRecv, sizeof(DataHeader), 0);
	DataHeader* header = (DataHeader*)szRecv;
	if (ret <= 0)
	{
		printf("客户端退出，任务结束 \n");
		return -1;
	}
	switch (header->cmd)
	{
	case CMD_LOGIN:
	{

		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		Login* login = (Login*)szRecv;
		printf("收到命令：CMD_LOGIN 数据长度：%d,usename=%s password=%s\n", login->dataLen, login->userName, login->password);
		LoginResult rest;
		send(_clientSock, (char*)&rest, sizeof(LoginResult), 0);
	}
	break;
	case CMD_LOGOUT:
	{

		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		Logout* logout = (Logout*)szRecv;
		printf("收到命令：CMD_LOGIN 数据长度：%d,usename=%s \n", logout->dataLen, logout->userName);
		LogoutResult rest;
		send(_clientSock, (char*)&rest, sizeof(LogoutResult), 0);
	}
	break;
	default:
	{
		DataHeader header = { 0 };
		header.cmd = CMD_ERROR;
		header.dataLen = 0;
		send(_clientSock, (char*)&header, sizeof(DataHeader), 0);
	}
	break;
	}
	return 0;
}

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
	


	while (true)
	{
		fd_set fdRead;
		fd_set fdWrite;
		fd_set fdExp;

		FD_ZERO(&fdRead);
		FD_ZERO(&fdWrite);
		FD_ZERO(&fdExp);

		FD_SET(_sock, &fdRead);
		FD_SET(_sock, &fdWrite);
		FD_SET(_sock, &fdExp);

		for (vector<SOCKET>::iterator i = g_clients.begin(); i != g_clients.end(); i++)
		{
			FD_SET(*i, &fdRead);
		}

		timeval t = { 1,0 };

		int rets=select(_sock + 1, &fdRead, &fdWrite, &fdExp,&t);
		if (rets < 0)
		{
			printf("select任务结束 \n");
			break;
		}

		if (FD_ISSET(_sock, &fdRead))
		{
			FD_CLR(_sock, &fdRead);
			//4.等待客户端连接
			sockaddr_in _client = {};
			int nAddrLen = sizeof(_client);
			SOCKET _clientSock = INVALID_SOCKET;
			_clientSock = accept(_sock, (sockaddr*)&_client, &nAddrLen);
			if (_clientSock == INVALID_SOCKET)
			{
				printf("错误,接收到无效客户端socket\n");
			}

			for (vector<SOCKET>::iterator i = g_clients.begin(); i !=g_clients.end(); i++)
			{
				NewUserJoin usj;
				send(*i, (char*)&usj, sizeof(NewUserJoin), 0);
			}

			printf("新客户端加入，IP=%s \n", inet_ntoa(_client.sin_addr));
			g_clients.push_back(_clientSock);
		}


		for (int i = 0; i <fdRead.fd_count; i++)
		{
			if (-1 == processor(fdRead.fd_array[i]))
			{
				auto iter = find(g_clients.begin(), g_clients.end(), fdRead.fd_array[i]);
				if (iter != g_clients.end())
				{
					g_clients.erase(iter);
				}
			}
		}
		
		//printf("空闲时间处理其他业务。。\n");
		
	}
	for (vector<SOCKET>::iterator i = g_clients.begin(); i !=g_clients.end(); i++)
	{
		closesocket(*i);
	}
	//8.关闭套接字
	closesocket(_sock);
	//清理环境
	WSACleanup();
	printf("已退出");
	getchar();
	return 0;
}
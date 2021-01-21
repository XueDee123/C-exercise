

//这个宏可以避免windows.h与socket2.h的宏冲突
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<WinSock2.h>
#include <stdio.h>

//在win平台下需要引入库文件不然WSAStartup会报错
//#pragma comment(lib,"ws2_32.lib")
//当然可以右击属性-》链接器-》输入-》附加依赖项

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


int processor(SOCKET _clientSock)
{
	//缓冲区
	char szRecv[1024] = {};
	//接收客户端的请求数据
	int ret = recv(_clientSock, szRecv, sizeof(DataHeader), 0);
	DataHeader* header = (DataHeader*)szRecv;
	if (ret <= 0)
	{
		printf("与服务器断开连接，任务结束 \n");
		return -1;
	}
	switch (header->cmd)
	{
	case CMD_LOGIN_RESULT:
	{
		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		LoginResult* re = (LoginResult*)szRecv;
		printf("收到命令：CMD_LOGIN_RESULT 数据长度：%d,result=%d \n", header->dataLen, re->result);
		
	}
	break;
	case CMD_LOGOUT_RESULT:
	{
		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		LogoutResult* re = (LogoutResult*)szRecv;
		printf("收到命令：CMD_LOGOUT_RESULT 数据长度：%d,result=%d \n", header->dataLen, re->result);
		
	}
	break;
	case CMD_NEW_USER_JOIN:
	{
		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		NewUserJoin* re = (NewUserJoin*)szRecv;
		printf("收到命令：CMD_NEW_USER_JOIN 数据长度：%d,socket=%d \n", header->dataLen, re->scok);

	}
	break;
	
	}
	return 0;
}

int main()
{
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	//启动socket
	WSAStartup(ver, &data);
	//1.建立一个socket
	SOCKET _sock= socket(AF_INET,SOCK_STREAM,0);
	if (_sock == INVALID_SOCKET)
	{
		printf("建立套接字失败");
	}
	else
	{
		printf("建立套接字成功");
	}
	//2.连接服务器
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int ret=connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (ret == SOCKET_ERROR)
	{
		printf("连接服务器失败");
	}
	else
	{
		printf("连接服务器成功");
	}
	
	
	while (true)
	{
		fd_set fdReads;
		FD_ZERO(&fdReads);
		FD_SET(_sock, &fdReads);
		timeval t = { 1,0 };
		int rets=select(_sock, &fdReads, 0, 0, &t);
		if (rets < 0)
		{
			printf("select任务结束\n");
			break;
		}
		if (FD_ISSET(_sock, &fdReads))
		{
			FD_CLR(_sock, &fdReads);
			if (-1 == processor(_sock))
			{
				printf("select任务结束\n");
				break;
			}
		}
		Login login;
		strcpy(login.userName, "Tom");
		strcpy(login.password, "123");
		send(_sock, (char*)&login, sizeof(Login), 0);
		Sleep(1000);
	}
	
	//7.关闭套接字

	closesocket(_sock);
	//清除windows socket环境
	WSACleanup();
	printf("已退出");
	getchar();
	return 0;
}
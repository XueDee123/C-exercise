

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
		//3.输入请求信息
		char cmdBuf[1024] = {};
		scanf("%s", &cmdBuf);
		//4.处理请求
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
			printf("不支持的命令\n");
		}
	
	}
	
	//7.关闭套接字

	closesocket(_sock);
	//清除windows socket环境
	WSACleanup();
	printf("已退出");
	getchar();
	return 0;
}


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
	//������
	char szRecv[1024] = {};
	//���տͻ��˵���������
	int ret = recv(_clientSock, szRecv, sizeof(DataHeader), 0);
	DataHeader* header = (DataHeader*)szRecv;
	if (ret <= 0)
	{
		printf("��������Ͽ����ӣ�������� \n");
		return -1;
	}
	switch (header->cmd)
	{
	case CMD_LOGIN_RESULT:
	{
		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		LoginResult* re = (LoginResult*)szRecv;
		printf("�յ����CMD_LOGIN_RESULT ���ݳ��ȣ�%d,result=%d \n", header->dataLen, re->result);
		
	}
	break;
	case CMD_LOGOUT_RESULT:
	{
		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		LogoutResult* re = (LogoutResult*)szRecv;
		printf("�յ����CMD_LOGOUT_RESULT ���ݳ��ȣ�%d,result=%d \n", header->dataLen, re->result);
		
	}
	break;
	case CMD_NEW_USER_JOIN:
	{
		recv(_clientSock, szRecv + sizeof(DataHeader), header->dataLen - sizeof(DataHeader), 0);
		NewUserJoin* re = (NewUserJoin*)szRecv;
		printf("�յ����CMD_NEW_USER_JOIN ���ݳ��ȣ�%d,socket=%d \n", header->dataLen, re->scok);

	}
	break;
	
	}
	return 0;
}

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
		fd_set fdReads;
		FD_ZERO(&fdReads);
		FD_SET(_sock, &fdReads);
		timeval t = { 1,0 };
		int rets=select(_sock, &fdReads, 0, 0, &t);
		if (rets < 0)
		{
			printf("select�������\n");
			break;
		}
		if (FD_ISSET(_sock, &fdReads))
		{
			FD_CLR(_sock, &fdReads);
			if (-1 == processor(_sock))
			{
				printf("select�������\n");
				break;
			}
		}
		Login login;
		strcpy(login.userName, "Tom");
		strcpy(login.password, "123");
		send(_sock, (char*)&login, sizeof(Login), 0);
		Sleep(1000);
	}
	
	//7.�ر��׽���

	closesocket(_sock);
	//���windows socket����
	WSACleanup();
	printf("���˳�");
	getchar();
	return 0;
}
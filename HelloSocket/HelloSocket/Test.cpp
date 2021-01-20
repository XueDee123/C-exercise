

//这个宏可以避免windows.h与socket2.h的宏冲突
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<WinSock2.h>


//在win平台下需要引入库文件不然WSAStartup会报错
//#pragma comment(lib,"ws2_32.lib")
//当然可以右击属性-》链接器-》输入-》附加依赖项



int main()
{
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	//启动socket
	WSAStartup(ver, &data);



	//清除windows socket环境
	WSACleanup();

	return 0;
}
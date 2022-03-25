#pragma comment(lib, "ws2_32.lib")
#include "myLibCP4_s.h"


int main(){
	setlocale(0, "");
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData)) {
		cerr << "������ ����������� ����������!\n";
		exit(1);
	}
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1280);//���������� hardware to network short ��� ���� ������������ ushort

	SOCKET s = socket (AF_INET, SOCK_STREAM, 0);

	bind(s, (SOCKADDR*)&addr, sizeof(addr));
	listen(s, SOMAXCONN);

	while (true) {
		sockaddr_in remote;
		int sizeRemote = sizeof(remote);
		SOCKET newSocket = accept(s, (struct sockaddr*)&remote, &sizeRemote);
		if (newSocket == 0)
			cerr << "������ � ����������� �������!\n";
		else
			cout << "����� ���������� �����������\n";
		main_func(newSocket);
	}
	system("pause");
	return 0;
}

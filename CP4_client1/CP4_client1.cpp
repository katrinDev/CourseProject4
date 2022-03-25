#pragma comment(lib, "ws2_32.lib")
#include "myLib_c1.h"

int main() {
	setlocale(0, "");
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData)) {
		cerr << "������ ����������� ����������!\n";
		exit(1);
	}
	SOCKADDR_IN peer;

	peer.sin_addr.s_addr = inet_addr("127.0.0.1");
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);//���������� hardware to network short ��� ���� ������������ ushort
	
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);//���������� ���������� ������
	if (connect(s, (SOCKADDR*)&peer, sizeof(peer))) {
		cout << "������ ����������� � �������!\n";
		exit(1);
	}
	cout << "�� ������� ������������ � �������\n";
	main_menu(s);

	system("pause");
	return 0;
}

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _AFXDLL
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <winsock2.h>

using namespace std;

class User {
	int ID;
	string login;
	string password;
	SOCKET socket;
public:
	User(SOCKET s);
	User(int id, string l, string p, SOCKET socket);
	int get_id();
	string get_login();
	string get_password();
	void set_login(string);
	void set_password(string);
	void set_socket(SOCKET Socket) { socket = Socket; }
};

class MarketSegment {
	string name;
	int export_percent;//процент от общего экспорта
	int number_of_suppliers;//количество поставщиков таких товаров
	int consumers_percent;//какой процент от общего числа потребителей предпочитают
public:
	MarketSegment();
	int get_export_percent() { return export_percent; }
	int get_consumers_percent() { return consumers_percent; }
	int get_number_of_suppliers() { return number_of_suppliers; }
};

void main_func(SOCKET newSocket);
void admin_menu(SOCKET newSocket);
void user_menu(SOCKET newSocket);
void user_manage_menu(SOCKET newSocket);
void menu_succesive_method(SOCKET newSocket);
void menu_paired_method(SOCKET newSocket);

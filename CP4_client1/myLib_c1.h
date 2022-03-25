#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _AFXDLL
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <winsock2.h>
#include <string>

using namespace std; 

void main_menu(SOCKET newS);
void admin_menu(SOCKET s);
void user_menu(SOCKET s);
template <class T>
int check(T num);

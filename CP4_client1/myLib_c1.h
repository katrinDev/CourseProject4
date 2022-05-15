#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _AFXDLL
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <winsock2.h>
#include <string>
#include <iomanip>

using namespace std; 

class Exception {
protected:
    string error;
public:
    string get_error() const { return error; }
};

class InputException : public Exception {
public:
	InputException(string error = "Некорректный ввод!\n") { this->error = error; }
};

class ConformityException : public Exception {
public:
    ConformityException(string error = "Некорректный запрос!\n") { this->error = error; }
};

template <class T>
int check(T num) {//шаблонная функции
    int k = 1;
    if (cin.fail() || num <= 0) {
        k = 0;
        cin.clear();
        cin.ignore(32767, '\n');
    }
    return k;
}


void main_menu(SOCKET newS);
void admin_menu(SOCKET s);
void user_menu(SOCKET s);

void menu_paired_method(SOCKET s);
void menu_succesive_method(SOCKET s);

bool login_pass_check(string name);
void authentication(SOCKET socket, int who);

ostream& setup(ostream& stream);

void user_manage_menu(SOCKET s);
void show_users(SOCKET s);
void add_users(SOCKET s);
void delete_users(SOCKET s);
void edit_users(SOCKET s);

void show_segments(SOCKET s);
void add_segments(SOCKET s);
void edit_segments(SOCKET s);
void delete_segments(SOCKET s);
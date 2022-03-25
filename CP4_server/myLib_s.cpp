#include "myLibCP4_s.h"
 
//доделать с сокетом!!
User::User(int id, string l, string p, SOCKET s) {
    ID = id;
    login = l;
    password = p;
	socket = s;
}

User::User(SOCKET s) : ID(0), login("unspecified"), password("unspecified"), socket(s) {};

int User::get_id() {
    return ID;
}
string User::get_login() {
    return login;
}
string User::get_password() {
    return password;
}

void User::set_login(string l) {
    login = l;
}
void User::set_password(string p) {
    password = p;
}

MarketSegment::MarketSegment() {
	name = "unknown";
	export_percent = 0;
	number_of_suppliers = 0;
	consumers_percent = 0;
}

void admin_menu(SOCKET newSocket) {
	char choice[50];
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			break;
		}
		case '2': {
			break;
		}
		case '3': {
			break;
		}
		case '4': {
			break;
		}
		case '5': {
			break;
		}
		case '6': {
			break;
		}
		case '7': {
			break;
		}
		case '8': {
			return;
		}

		}
	}
}

void user_menu(SOCKET newSocket) {
	char choice[50];
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			break;
		}
		case '2': {
			break;
		}
		case '3': {
			break;
		}
		case '4': {
			return;
		}

		}
	}

}


void main_func(SOCKET newSocket) {
	char choice[50];
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			//авторизация
			admin_menu(newSocket);
			break;
		}
		case '2': {
			//авторизация
			user_menu(newSocket);
			break;
		}
		case '3': {
			cout << "Пользователь завершил работу\n";
			system("pause");
			exit(0);
		}

		}
	}
}
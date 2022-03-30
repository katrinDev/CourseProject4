#include "myLibCP4_s.h"
 
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

//-����� ������ ���������-
void menu_paired_method(SOCKET newSocket) {
	char choice[50];
	while (1) {
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			cout << "\n������� �������� ������������\n";
			break;
		}
		case '2': {
			cout << "\n������������� �������\n";
			break;
		}
		case '3': {
			cout << "\n���������� �������\n";
			break;
		}
		case '4': {
			return;
		}
		}

	}
}

//-����� ���������������� ���������-
void menu_succesive_method(SOCKET newSocket) {
	char choice[50];
	while (1) {
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);

		switch (choice[0]) {
		case '1': {
			cout << "\n������������� ��������������� ������\n";
			break;
		}
		case '2': {
			cout << "\n�������� �������� �����\n";
			break;
		}
		case '3': {
			cout << "\n���������� �������\n";
			break;
		}
		case '4': {
			return;
		}
		}
	}
}

void user_manage_menu(SOCKET newSocket) {
	char choice[50];

	while (true) {
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);

		switch (choice[0]) {
		case '1': {
			cout << "\n�������� ������������\n";
			break;
		}
		case '2': {
			cout << "\n������������� ������ ������������\n";
			break;
		}
		case '3': {
			cout << "\n������� ������������\n";
			break;
		}
		case '4': {
			cout << "\n����������� ������ � ��������� �����\n";
			break;
		}
		case '5': {
			return;
		}
		}
	}
}


void admin_menu(SOCKET newSocket) {
	char choice[50];
	while (1) {
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			cout << "\n����������� ������ � ��������� ����� � ��������� �����\n";
			break;
		}
		case '2': {
			menu_paired_method(newSocket);
			break;
		}
		case '3': {
			menu_succesive_method(newSocket);
			break;
		}
		case '4': {
			cout << "\n�������� �������\n";
			break;
		}
		case '5': {
			cout << "\n������������� ������ � ���������\n";
			break;
		}
		case '6': {
			cout << "\n������� ������� �� ������\n";
			break;
		}
		case '7': {
			user_manage_menu(newSocket);
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
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			cout << "\n����������� ������ � ��������� �����\n";
			break;
		}
		case '2': {
			menu_paired_method(newSocket);
			break;
		}
		case '3': {
			menu_succesive_method(newSocket);
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
			//�����������
			admin_menu(newSocket);
			break;
		}
		case '2': {
			//�����������
			user_menu(newSocket);
			break;
		}
		case '3': {
			cout << "������������ �������� ������\n";
			system("pause");
			exit(0);
		}

		}
	}
}
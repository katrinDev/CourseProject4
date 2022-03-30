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

//-МЕТОД ПАРНЫХ СРАВНЕНИЙ-
void menu_paired_method(SOCKET newSocket) {
	char choice[50];
	while (1) {
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			cout << "\nМатрица бинарных предпочтений\n";
			break;
		}
		case '2': {
			cout << "\nРедактировать матрицу\n";
			break;
		}
		case '3': {
			cout << "\nПроизвести расчеты\n";
			break;
		}
		case '4': {
			return;
		}
		}

	}
}

//-МЕТОД ПОСЛЕДОВАТЕЛЬНЫХ СРАВНЕНИЙ-
void menu_succesive_method(SOCKET newSocket) {
	char choice[50];
	while (1) {
		system("cls");
		recv(newSocket, choice, sizeof(choice), 0);

		switch (choice[0]) {
		case '1': {
			cout << "\nРедактировать предварительные оценки\n";
			break;
		}
		case '2': {
			cout << "\nСравнить сегменты рынка\n";
			break;
		}
		case '3': {
			cout << "\nПроизвести расчеты\n";
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
			cout << "\nДобавить пользователя\n";
			break;
		}
		case '2': {
			cout << "\nРедактировать данные пользователя\n";
			break;
		}
		case '3': {
			cout << "\nУдалить пользователя\n";
			break;
		}
		case '4': {
			cout << "\nПросмотреть данные в табличной форме\n";
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
			cout << "\nПросмотреть данные о сегментах рынка в табличной форме\n";
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
			cout << "\nДобавить сегмент\n";
			break;
		}
		case '5': {
			cout << "\nРедактировать данные о сегментах\n";
			break;
		}
		case '6': {
			cout << "\nУдалить сегмент из списка\n";
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
			cout << "\nПросмотреть данные в табличной форме\n";
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
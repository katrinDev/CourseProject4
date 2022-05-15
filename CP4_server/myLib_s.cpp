#include "myLibCP4_s.h"

User::User(string l, string p, SOCKET s) : socket(s), login(l), password(p) {};

int User::id = 0;
map<int, User> User::users;

void User::file_input() {
	ofstream file("Users.txt");

	for (auto it = users.begin(); it != users.end(); it++) {
		file << it->second;
	}
		
	file.close();
}

void User::delete_user(int ID) {
	users.erase(ID);
	id--;
}

string User::get_login() const{
    return login;
}
string User::get_password() const {
    return password;
}

SOCKET User::get_socket() const {
	return socket;
}

void User::set(SOCKET s, string l, string p) {
	socket = s;
	login = l;
	password = p;
}

istream& operator >>(istream& s, User& user) {
	string login, password;
	s >> login >> password;
	user.login = encryption(login, 2);
	user.password = encryption(password, 2);
	return s;
}

ostream& operator <<(ostream& s, User& user) {
	s << encryption(user.login, 1) << "   " << encryption(user.password, 1) << endl;
	return s;
}

//МЕТОДЫ MarketSegment

MarketSegment::MarketSegment(string name, int export_percent, int consumers, int suppliers, SegmentProfitability profit){
	this->name = name;
	this->export_percent = export_percent;
	consumers_percent = consumers;
	number_of_suppliers = suppliers;
	segment_profit = profit;
}

int MarketSegment::id = 0;
map<int, MarketSegment> MarketSegment::segments;

void MarketSegment::file_input() {
	ofstream file("Segments.txt");

	for (auto it = segments.begin(); it != segments.end(); it++) {
		file << it->second;
	}

	file.close();
}

void MarketSegment::delete_segment(int ID) {
	segments.erase(ID);
	--id;
}

ostream& operator <<(ostream& s, MarketSegment& segment) {
	s << segment.name << endl;
	s << segment.export_percent << "   "
		<< segment.consumers_percent  << "   " << segment.number_of_suppliers <<"   " << 
		segment.segment_profit << "   " << endl;
	return s;
}

istream& operator >>(istream& s, MarketSegment& segment) {
	s >> ws;
	getline(s, segment.name);
	s >> segment.export_percent >>
		segment.consumers_percent >> segment.number_of_suppliers >>
		segment.segment_profit;
	return s;
}

//МЕТОДЫ SegmentProfitability

ostream& operator<<(ostream& s, SegmentProfitability& profitability) {
	s << profitability.rate_of_return << "   " << profitability.ROI;
	return s;
}

istream& operator>>(istream& s, SegmentProfitability& profitability) {
	s >> profitability.rate_of_return >> profitability.ROI;
	return s;
}

void admin_menu(SOCKET newSocket) {
	char choice[50];
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			show_segments(newSocket);
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
			add_segments(newSocket);
			break;
		}
		case '5': {
			edit_segments(newSocket);
			break;
		}
		case '6': {
			delete_segments(newSocket);
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
			show_segments(newSocket);
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
	string user;
	try {
		ifstream file("Segments.txt");
		if (!file)
			throw FileException();
		MarketSegment segment;
		while (file >> segment)
			MarketSegment::add_segment(segment);
		file.close();
	}
	catch (const Exception& exception) {
		cout << exception.get_error() << endl;
		Sleep(1000);
		return;
	}
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			authentication(newSocket, 1);
			break;
		}
		case '2': {
			authentication(newSocket, 2);
			break;
		}
		case '3': {
			cout << "Пользователь c сокета " << newSocket << " завершил работу\n";
			exit(0);
		}
		}
	}
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
			show_users(newSocket);
			break;
		}
		case '2': {
			add_users(newSocket);
			break;
		}
		case '3': {
			delete_users(newSocket);
			break;
		}
		case '4': {
			edit_users(newSocket);
			break;
		}
		case '5': {
			return;
		}
		}
	}
}

string encryption(string password, int num) {
	string alf = "abcdefghijklmnopqrstuvwxyz";
	string enc = "adventurbcfghijklmopqswxyz";
	char ch;

	for (size_t j = 0; j <= password.length(); j++) {
		ch = password[j];
		if (num == 1) {
			if (isalpha(ch)) {
				for (size_t i = 0; i <= alf.length(); i++) {
					if (alf[i] == ch) {
						ch = enc[i];
						break;
					}
					if (isupper(ch)) {
						if (ch == toupper(alf[i])) {
							ch = (char)toupper(enc[i]);
							break;
						}
					}
				}
			}
			if (isdigit(ch)) {
				ch++;
			}
		}
		if (num == 2) {
			if (isalpha(ch)) {
				for (size_t i = 0; i <= enc.length(); i++) {
					if (enc[i] == ch) {
						ch = alf[i];
						break;
					}
					if (isupper(ch)) {
						if (ch == toupper(enc[i])) {
							ch = (char)toupper(alf[i]);
							break;
						}
					}
				}
			}
			if (isdigit(ch)) {
				ch--;
			}
		}
		password[j] = ch;
	}
	return password;
}



void authentication(SOCKET socket, int who) {
	User user;
	char login[50], password[50], buf[100] ;
	ifstream file("Users.txt");

	try {
		if (!file)
			throw FileException();
	
		while (file >> user)
			User::add_user(user);
		file.close();


		while (1) {
			try {
				recv(socket, login, sizeof(login), 0);
				recv(socket, password, sizeof(password), 0);
				bool a = false;
				for (auto it = User::users.begin(); it != User::users.end(); it++) {//ИТЕРАТОРЫ
					if (((who == 1 && it->first == 1) || who == 2) && (it->second.login == login && it->second.password == password)) {
						a = true;
						user.set(socket, login, password);
						break;
					}
				}
				if (!a)
					throw ConformityException();
				strcpy(buf, "cool\0");
				send(socket, buf, sizeof(buf), 0);
				cout << "Пользователь " << user.login << " успешно вошел в систему, сокет " << user.socket << endl;
				who == 1 ? admin_menu(socket) : user_menu(socket);
				break;
			}
			catch (const ConformityException& exception) {
				strcpy(buf, exception.get_error().c_str());
				send(socket, buf, sizeof(buf), 0);
				recv(socket, buf, sizeof(buf), 0);
				if (buf == "n")
					break;
			}
		}
	}
	catch (const Exception& exception) {
		cout << exception.get_error();
	}
	return;
}

void show_users(SOCKET s) {
	char size[10], login[50], password[50];
	_itoa(User::id, size, 10);
	send(s, size, sizeof(size), 0);
	for (auto it = User::users.begin(); it != User::users.end(); it++) {
		strcpy(login, it->second.login.c_str());
		send(s, login, sizeof(login), 0);
		strcpy(password, it->second.password.c_str());
		send(s, password, sizeof(password), 0);
	}
}

void add_users(SOCKET s) {
	show_users(s);
	char login[50], password[50];
	recv(s, login, sizeof(login), 0);
	recv(s, password, sizeof(password), 0);
	User user(login, password);
	User::add_user(user);
	User::file_input();
}

void delete_users(SOCKET s) {
	char buf[50], n[5];
	int ID;
	show_users(s);
	while (1) {
		try {
			recv(s, buf, sizeof(buf), 0);
			ID = atoi(buf);
			if (ID > User::id)
				throw ConformityException();
			send(s, "cool", sizeof("cool"), 0);
			User::delete_user(ID);
			User::file_input();
			break;
		}
		catch (const ConformityException& exception) {
			strcpy(buf, exception.get_error().c_str());
			send(s, buf, sizeof(buf), 0);
			recv(s, n, sizeof(n), 0);
			if (n == "n")
				break;
		}
	}
}

void edit_users(SOCKET s) {
	char buf[50], n[5];
	char login[50], password[50];
	int ID;
	show_users(s);
	while (1) {
		try {
			recv(s, buf, sizeof(buf), 0);
			ID = atoi(buf);
			if (ID > User::id)
				throw ConformityException();
			send(s, "cool", sizeof("cool"), 0);
			recv(s, buf, sizeof(buf), 0);
			switch (buf[0]) {
			case '1': {
				recv(s, login, sizeof(login), 0);
				User::users[ID].set_login(login);
				break;
			}
			case '2': {
				recv(s, password, sizeof(password), 0);
				User::users[ID].set_password(password);
				break;
			}
			}

			User::file_input();
			break;
		}
		catch (const ConformityException& exception) {
			strcpy(buf, exception.get_error().c_str());
			send(s, buf, sizeof(buf), 0);
			recv(s, n, sizeof(n), 0);
			if (n == "n")
				break;
		}
	}
}


void show_segments(SOCKET s) {
	char size[10], name[50], inf[10];
	_itoa(MarketSegment::id, size, 10);
	send(s, size, sizeof(size), 0);
	for (auto it = MarketSegment::segments.begin(); it != MarketSegment::segments.end(); it++) {
		strcpy(name, it->second.name.c_str());
		send(s, name, sizeof(name), 0);

		_itoa(it->second.export_percent, inf, 10);
		send(s, inf, sizeof(inf), 0);

		_itoa(it->second.consumers_percent, inf, 10);
		send(s, inf, sizeof(inf), 0);

		_itoa(it->second.number_of_suppliers, inf, 10);
		send(s, inf, sizeof(inf), 0);

		_itoa(it->second.segment_profit.rate_of_return, inf, 10);
		send(s, inf, sizeof(inf), 0);

		_itoa(it->second.segment_profit.ROI, inf, 10);
		send(s, inf, sizeof(inf), 0);
	}
}

void add_segments(SOCKET s) {
	show_segments(s);
	char name[50], export_percent[10], consumers[10], suppliers[10], rate_of_return[10], roi[10];
	int exp, c, suppliers_int, ror, roi_int;

	recv(s, name, sizeof(name), 0);
	recv(s, export_percent, sizeof(export_percent), 0);
	exp = atoi(export_percent);
	recv(s, consumers, sizeof(consumers), 0);
	c = atoi(consumers);
	recv(s, suppliers, sizeof(suppliers), 0);
	suppliers_int = atoi(suppliers);
	recv(s, rate_of_return, sizeof(rate_of_return), 0);
	ror = atoi(rate_of_return);
	recv(s, roi, sizeof(roi), 0);
	roi_int = atoi(roi);

	SegmentProfitability profit(ror, roi_int);
	MarketSegment segment(name, exp, c, suppliers_int, profit);
	MarketSegment::add_segment(segment);
	MarketSegment::file_input();
}

void delete_segments(SOCKET s) {
	char buf[50], n[5];
	int ID;
	show_segments(s);
	
	while (1) {
		try {
			recv(s, buf, sizeof(buf), 0);
			ID = atoi(buf);
			if (ID > MarketSegment::id)
				throw ConformityException();
			send(s, "cool", sizeof("cool"), 0);
			MarketSegment::delete_segment(ID);
			MarketSegment::file_input();
			break;
		}
		catch (const ConformityException& exception) {
			strcpy(buf, exception.get_error().c_str());
			send(s, buf, sizeof(buf), 0);
			recv(s, n, sizeof(n), 0);
			if (n == "n")
				break;
		}
	}
}

void edit_segments(SOCKET s) {
	char buf[50], n[5];
	char name[50], export_percent[10], consumers[10], suppliers[10], rate_of_return[10], roi[10];
	int ID;
	show_segments(s);

	while (1) {
		try {
			recv(s, buf, sizeof(buf), 0);
			ID = atoi(buf);
			if (ID > MarketSegment::id)
				throw ConformityException();
			send(s, "cool", sizeof("cool"), 0);

			recv(s, buf, sizeof(buf), 0);
			switch (buf[0]) {
			case '1': {
				recv(s, name, sizeof(name), 0);
				MarketSegment::segments[ID].set_name(name);
				break;
			}
			case '2': {
				recv(s, export_percent, sizeof(export_percent), 0);
				int exp = atoi(export_percent);
				MarketSegment::segments[ID].set_export_percent(exp);
				break;
			}
			case '3': {
				recv(s, consumers, sizeof(consumers), 0);
				int c = atoi(consumers);
				MarketSegment::segments[ID].set_consumers(c);
				break;
			}

			case '4': {
				recv(s, suppliers, sizeof(suppliers), 0);
				int suppliers_int = atoi(suppliers);
				MarketSegment::segments[ID].set_suppliers(suppliers_int);
				break;
			}
			case '5': {
				recv(s, rate_of_return, sizeof(rate_of_return), 0);
				int ror = atoi(rate_of_return);
				MarketSegment::segments[ID].set_rate_of_return(ror);
				break;
			}
			case '6': {
				recv(s, roi, sizeof(roi), 0);
				int roi_int = atoi(roi);
				MarketSegment::segments[ID].set_roi(roi_int);
				break;
			}
			}

			MarketSegment::file_input();
			break;
		}
		catch (const ConformityException& exception) {
			strcpy(buf, exception.get_error().c_str());
			send(s, buf, sizeof(buf), 0);
			recv(s, n, sizeof(n), 0);
			if (n == "n")
				break;
		}
	}
}
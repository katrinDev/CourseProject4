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
	map<int, int> estimates;
	int size = MarketSegment::id;
	vector<vector<int>> matrix(size, vector<int>(size));
	try {
		ifstream file("Matrix.txt");
		if (!file)
			throw(FileException());
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				if (i != j)
					file >> matrix[i][j];
			}
	}
	catch (const Exception& exception) {
		cout << exception.get_error();
		return;
	}
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			show_segments(newSocket);
			break;
		}
		case '2': {
			menu_paired_method(newSocket, matrix, estimates);
			break;
		}
		case '3': {
			if (estimates.empty())
				send(newSocket, "no", sizeof("no"), 0);
			else {
				send(newSocket, "good", sizeof("good"), 0);
				menu_succesive_method(newSocket, estimates);
			}
			break;
		}
		case '4': {
			add_segments(newSocket, matrix);
			break;
		}
		case '5': {
			edit_segments(newSocket);
			break;
		}
		case '6': {
			delete_segments(newSocket, matrix);
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
	map<int, int> estimates;
	int size = MarketSegment::id;
	vector<vector<int>> matrix(size, vector<int>(size));
	try {
		ifstream file("Matrix.txt");
		if (!file)
			throw(FileException());
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				if (i != j)
					file >> matrix[i][j];
			}
	}
	catch (const Exception& exception) {
		cout << exception.get_error();
		return;
	}
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			show_segments(newSocket);
			break;
		}
		case '2': {
			menu_paired_method(newSocket, matrix, estimates);
			break;
		}
		case '3': {
			if (estimates.empty())
				send(newSocket, "no", sizeof("no"), 0);
			else {
				send(newSocket, "good", sizeof("good"), 0);
				menu_succesive_method(newSocket, estimates);
			}
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
void menu_paired_method(SOCKET newSocket, vector<vector<int>>& matrix, map<int, int>& estimates) {
	
	char choice[50];
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);
		switch (choice[0]) {
		case '1': {
			show_matrix(newSocket, matrix);
			break;
		}
		case '2': {
			edit_matrix(newSocket, matrix);
			break;
		}
		case '3': {
			make_paired_calculations(newSocket, matrix, estimates);
			break;
		}
		case '4': {
			return;
		}
		}

	}
}

//-МЕТОД ПОСЛЕДОВАТЕЛЬНЫХ СРАВНЕНИЙ-
void menu_succesive_method(SOCKET newSocket, map<int, int>& estimates) {
	char choice[50];
	while (1) {
		recv(newSocket, choice, sizeof(choice), 0);

		switch (choice[0]) {
		case '1': {
			show_estimates(newSocket, estimates);
			break;
		}
		case '2': {
			edit_estimates(newSocket, estimates);
			break;
		}
		case '3': {
			make_succesive_calculations(newSocket, estimates);
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
				for (auto it = User::users.begin(); it != User::users.end(); it++) {
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
		Sleep(1000);
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

void add_segments(SOCKET s, vector<vector<int>>& matrix) {
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

	show_segments(s);
	show_matrix(s, matrix);

	char id_new_char[10], value_char[2];
	int id_new = MarketSegment::id, value;
	_itoa(id_new, id_new_char, 10);

	send(s, id_new_char, sizeof(id_new_char), 0);

	matrix.resize(id_new);
	int new_index = id_new - 1;

	matrix[new_index].resize(id_new);

	for (int i = 0; i < new_index; i++) {
		matrix[i].resize(id_new);
		recv(s, value_char, sizeof(value_char), 0);
		value = atoi(value_char);
		matrix[new_index][i] = value;
		!value ? matrix[i][new_index] = 1 : matrix[i][new_index] = 0;
	}

	matrix_file_input(matrix);
}


void delete_segments(SOCKET s, vector<vector<int>>& matrix){
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

			ID = MarketSegment::id;
			matrix.resize(ID);
			for (int i = 0; i < ID; i++)
				matrix[i].resize(ID);
			matrix_file_input(matrix);
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


void show_matrix(SOCKET s, const vector<vector<int>>& matrix) {
	char n[5], value[10];
	_itoa(matrix.size(), n, 10);
	send(s, n, sizeof(n), 0);

	for (auto it = matrix.begin(); it != matrix.end(); it++) {
		for (auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {
			_itoa(*inner_it, value, 10);
			send(s, value, sizeof(value), 0);
		}
	}
}


void edit_matrix(SOCKET s, vector<vector<int>>& matrix) {
	char n[5], i_char[10], j_char[10];
	int i, j;
	show_matrix(s, matrix);

	_itoa(matrix.size(), n, 10);
	send(s, n, sizeof(n), 0);
	
	recv(s, i_char, sizeof(i_char), 0);
	i = atoi(i_char);
	recv(s, j_char, sizeof(j_char), 0);
	j = atoi(j_char);

	i--; j--;
	if (!matrix[i][j]) {
		matrix[i][j] = 1;
		matrix[j][i] = 0;
	}
	else {
		matrix[i][j] = 0;
		matrix[j][i] = 1;
	}

	matrix_file_input(matrix);
}

void matrix_file_input(const vector<vector<int>>& matrix) {
	ofstream file("Matrix.txt");
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (unsigned int j = 0; j < matrix[i].size(); j++) {
			if(i != j)
				file << matrix[i][j] << "   ";
		}
		file << endl;
	}
	file.close();
}

void make_paired_calculations(SOCKET s, const vector<vector<int>>& matrix, map<int, int>& estimates){
	//определяем цену выбора для каждого сегмента
	char cost_char[10], n_char[10];
	unsigned int n = matrix.size();

	_itoa(n, n_char, 10);
	send(s, n_char, sizeof(n_char), 0);

	vector<int> costs(n);
	int sum = 0;
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < matrix[i].size(); j++) {
			costs[i] += matrix[i][j];
		}
		_itoa(costs[i], cost_char, 10);
		send(s, cost_char, sizeof(cost_char), 0);
		sum += costs[i];
	}

	map<float, int> weights;
	char weight_char[10];
	float weight_float;

	//определяем вес выбора для каждого сегмента рынка
	for (unsigned int i = 0; i < n; i++) {
		weight_float = float(costs[i]) / float(sum);
		sprintf(weight_char, "%.2f", weight_float);
		send(s, weight_char, sizeof(weight_char), 0);

		weights.insert(make_pair(weight_float, i + 1));
	}
	
	//отправляем итоговую последовательность
	char str[30] = "";
	stringstream ss;
	for (auto it = weights.rbegin(); it != weights.rend(); it++) {
		ss << "C" << it->second;
		
		if(it != --weights.rend())
			ss << ",";
	}
	ss >> str;
	send(s, str, sizeof(str), 0);

	//заполнение предварительных оценок
	const int diff = 100 / weights.size();
	int id = 0, i = 0;
	for (auto it = weights.rbegin(); it != weights.rend(); it++) {
		id = it->second;
		estimates.insert(make_pair(id, 100 - diff * i));
		i++;
	}
}

void show_estimates(SOCKET s, map<int, int>& estimates) {
	char n[10], id_char[10], estimate_char[10];

	_itoa(estimates.size(), n, 10);
	send(s, n, sizeof(n), 0);
	for (auto it = estimates.begin(); it != estimates.end(); it++) {
		_itoa(it->first, id_char, 10);
		send(s, id_char, sizeof(id_char), 0);
		_itoa(it->second, estimate_char, 10);
		send(s, estimate_char, sizeof(estimate_char), 0);
	}
}

void edit_estimates(SOCKET s, map<int, int>& estimates) {
	char id_char[10], new_estimate_char[10], buf[50], answer[5];
	int id, new_estimate, old_estimate;
	show_segments(s);
	show_estimates(s, estimates);

	vector<int> near_estimates;
	for (auto it = estimates.begin(); it != estimates.end(); it++) {
		near_estimates.push_back(it->second);
	}
	sort(near_estimates.begin(), near_estimates.end());


	recv(s, id_char, sizeof(id_char), 0);
	id = atoi(id_char);

	while (1) {
		try {
			recv(s, new_estimate_char, sizeof(new_estimate_char), 0);
			new_estimate = atoi(new_estimate_char);

			old_estimate = estimates[id];

			int before = 0, after = 0;
			for (auto it = near_estimates.begin(); it != near_estimates.end(); it++) {
				if (*it == old_estimate) {
					before = *(it - 1);
					after = *(it + 1);
					break;
				}
			}

			if (new_estimate < before || new_estimate > after)
				throw ConformityException();
			send(s, "cool", sizeof("cool"), 0);
			estimates[id] = new_estimate;
			break;
		}
		catch (const ConformityException& exception) {
			strcpy(buf, exception.get_error().c_str());
			send(s, buf, sizeof(buf), 0);
			recv(s, answer, sizeof(answer), 0);
			if (answer == "n")
				break;
		}
	}
		
}

void make_succesive_calculations(SOCKET s, map<int, int>& estimates) {
	char weight_char[10], n_char[10];
	float weight_float;

	unsigned int n = estimates.size();
	_itoa(n, n_char, 10);
	send(s, n_char, sizeof(n_char), 0);

	int sum = 0;
	for (auto it = estimates.begin(); it != estimates.end(); it++) {
		sum += it->second;
	}
	map<float, int> weights;

	//определяем вес выбора для каждого сегмента рынка
	for (unsigned int i = 1; i <= estimates.size(); i++) {
		weight_float = float(estimates[i]) / float(sum);
		sprintf(weight_char, "%.2f", weight_float);
		send(s, weight_char, sizeof(weight_char), 0);

		weights.insert(make_pair(weight_float, i));
	}

	//отправляем итоговую последовательность
	char str[30] = "";
	stringstream ss;
	for (auto it = weights.rbegin(); it != weights.rend(); it++) {
		ss << "C" << it->second;

		if (it != --weights.rend())
			ss << ",";
	}
	ss >> str;
	send(s, str, sizeof(str), 0);
}

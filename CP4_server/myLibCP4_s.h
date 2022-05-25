#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _AFXDLL
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <winsock2.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class User {
	string login;
	string password;
	SOCKET socket;
public:
	static int id;
	static map<int, User> users;
	User(string l = "unspecified", string p = "unspecified", SOCKET s = SOCKET());
	string get_login() const;
	string get_password() const;
	void set_login(string l) { login = l; }
	void set_password(string p) { password = p; }
	SOCKET get_socket() const;
	void set(SOCKET s, string l, string p);

	static void add_user(User& user) { users.insert(make_pair(++id, user)); }
	static void delete_user(int ID);
	static void file_input();
	friend void authentication(SOCKET socket, int who);

	friend istream& operator >>(istream& s, User& user);
	friend ostream& operator <<(ostream& s, User& user);
	friend void show_users(SOCKET s);
	friend void add_users(SOCKET s);
};


class SegmentProfitability {
	int rate_of_return;//норма прибыли
	int ROI;//доходность на вложенный капитал (Return on investment)
public:
	SegmentProfitability(int rate = 0, int roi = 0) : rate_of_return(rate), ROI(roi) {}
	friend ostream& operator<<(ostream& s, SegmentProfitability& profitability);
	friend istream& operator>>(istream& s, SegmentProfitability& profitability);
	friend void show_segments(SOCKET s);

	void set_rate_of_return(int ror) { rate_of_return = ror; }
	void set_roi(int roi) { ROI = roi; }
	friend void edit_segments(SOCKET s);
};

class MarketSegment {
	string name;
	int export_percent;
	int consumers_percent;
	int number_of_suppliers;
	SegmentProfitability segment_profit;
public:
	MarketSegment(string name = "unspecified", int export_percent = 0, int consumers = 0, int suppliers = 0, SegmentProfitability profit = SegmentProfitability());

	static int id;
	static map<int, MarketSegment> segments;
	static void file_input();
	static void add_segment(MarketSegment& segment) { segments.insert(make_pair(++id, segment)); }
	static void delete_segment(int ID);


	int get_export_percent() { return export_percent; }
	string get_name() { return name; }
	int get_consumers_percent() { return consumers_percent; }
	int get_number_of_suppliers() { return number_of_suppliers; }

	void set_name(string name) { this->name = name; }
	void set_export_percent(int export_percent) { this->export_percent = export_percent; }
	void set_consumers(int consumers) { consumers_percent = consumers; }
	void set_suppliers(int suppliers) { number_of_suppliers = suppliers; }

	void set_rate_of_return(int ror) { segment_profit.set_rate_of_return(ror); }
	void set_roi(int roi) { segment_profit.set_roi(roi); }
	friend ostream& operator<<(ostream& s, MarketSegment& segment);
	friend istream& operator >>(istream& s, MarketSegment& user);
	friend void show_segments(SOCKET s);
};


class Exception {
protected:
	string error;
public:
	string get_error() const { return error; }
};

class FileException : public Exception {
public:
	FileException(string error = "Ошибка открытия файла!\n") { this->error = error; }
};

class ConformityException : public Exception {
public:
	ConformityException(string error = "Некорректный запрос!\n") { this->error = error; }
};


void main_func(SOCKET newSocket);
void admin_menu(SOCKET newSocket);
void user_menu(SOCKET newSocket);
void user_manage_menu(SOCKET newSocket);
string encryption(string password, int num);

void authentication(SOCKET socket, int who);
ostream& setup(ostream& stream);
void show_users(SOCKET s);
void add_users(SOCKET s);
void delete_users(SOCKET s);
void edit_users(SOCKET s);
istream& operator >>(istream& s, User& user);
ostream& operator <<(ostream& s, User& user);

ostream& operator <<(ostream& s, MarketSegment& segment);
ostream& operator<<(ostream& s, SegmentProfitability& profitability);
void show_segments(SOCKET s);
void add_segments(SOCKET s, vector<vector<int>>& matrix);
void edit_segments(SOCKET s);
void delete_segments(SOCKET s, vector<vector<int>>& matrix);

void menu_paired_method(SOCKET newSocket, vector<vector<int>>& matrix, map<int, int>& estimates);
void show_matrix(SOCKET s, const vector<vector<int>>& matrix);
void edit_matrix(SOCKET s, vector<vector<int>>& matrix);
void make_paired_calculations(SOCKET s, const vector<vector<int>>& matrix, map<int, int>& estimates);
void matrix_file_input(const vector<vector<int>>& matrix);

void menu_succesive_method(SOCKET newSocket, map<int, int>& estimates);
void edit_estimates(SOCKET s, map<int, int>& estimates);
void make_succesive_calculations(SOCKET s, map<int, int>& estimates);
void show_estimates(SOCKET s, map<int, int>& estimates);

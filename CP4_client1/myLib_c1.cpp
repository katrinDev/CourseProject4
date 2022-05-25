#include "myLib_c1.h"

void main_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;
    while (1) {
        system("cls");

        cout << "\n\n";
        cout << "\t\t   �����������" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * \n\n";
        cout << "\t1. ����� ��� ���������������\n";
        cout << "\t2. ����� ��� �������������\n";
        cout << "\t3. �����\n" << endl;
        do {
            cout << "\t   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 3)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i){
        case 1: {
            authentication(s, 1);
            break;
        }
        case 2: {
            authentication(s, 2);
            break;
        }
        case 3: {
            return;
        }
        default: {
            cout << "\n\t��������� �����!\n";
            break;
        }
        }
        
    }
}


void admin_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (true) {
        system("cls");
        cout << "\n";
        cout << "\t���� ��������������\n";
        cout << "* * * * * * * * * * * * * * * * * *\n";
        cout << "1. ����������� ������ � ��������� ����� � ��������� �����\n";
        cout << "2. ����� ������ ���������\n";
        cout << "3. ����� ���������������� ���������\n";
        cout << "4. �������� �������\n";
        cout << "5. ������������� ������ � ���������\n";
        cout << "6. ������� ������� �� ������\n";
        cout << "7. ���������� ��������������\n";
        cout << "8. ��������� ������\n\n";
        do {
            cout << "   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 8)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            system("cls");
            show_segments(s);
            system("pause");
            break;
        }
        case 2: {
            menu_paired_method(s);
            break;
        }
        case 3: {
            char answer[10];
            recv(s, answer, sizeof(answer), 0);
            if(!strcmp(answer, "good"))
                menu_succesive_method(s);
            else {
                cout << "\n���������� ������ �� �������� ������ ������ ���������!\n";
                Sleep(1500);
            }
            break;
        }
        case 4: {
            system("cls");
            add_segments(s);
            break;
        }
        case 5: {
            system("cls");
            edit_segments(s);
            break;
        }
        case 6: {
            system("cls");
            delete_segments(s);
            break;
        }
        case 7: {
            user_manage_menu(s);
            break;
        }
        case 8: {
            return;
        }
        default: {
            cout << "\n��������� �����!\n";
            break;
        }
        }
    }
}

void user_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (true) {
        system("cls");
        cout << "\n";
        cout << "\t ���� ������������\n";
        cout << "* * * * * * * * * * * * * * * * * * *\n";
        cout << "1. ����������� ������ � ��������� �����\n";
        cout << "2. ����� ������ ���������\n";
        cout << "3. ����� ���������������� ���������\n";
        cout << "4. ��������� ������\n";
        do {
            cout << "   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            system("cls");
            show_segments(s);
            system("pause");
            break;
        }
        case 2: {
            menu_paired_method(s);
            break;
        }
        case 3: {
            menu_succesive_method(s);
            break;
        }
        case 4: {
            return;
        }
        default: {
            cout << "\n��������� �����!\n";
            break;
        }
        }
    }
}

void user_manage_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (true) {
        system("cls");
        cout << "\n";
        cout << "\t���� ���������� ��������������" << endl;
        cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1. ����������� ������ � ��������� �����" << endl;
        cout << "2. �������� ������������" << endl;
        cout << "3. ������� ������������" << endl;
        cout << "4. ������������� ������ ������������" << endl;
        cout << "5. ����� � ���� ��������������\n" << endl;
        do {
            cout << "   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 5)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            show_users(s);
            system("pause");
            break;
        }
        case 2: {
            add_users(s);
            break;
        }
        case 3: {
            delete_users(s);
            break;
        }
        case 4: {
            edit_users(s);
            break;
        }
        case 5: {
            return;
        }
        default: {
            cout << "\n��������� �����!\n";
            break;
        }
        }
    }
}

//-����� ������ ���������-
void menu_paired_method(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (1) {
        system("cls");

        cout << "\n";
        cout << "\t   ����� ������ ���������" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * *\n\n";
        cout << "1. ����������� ������� �������� ������������\n";
        cout << "2. ������������� �������\n";
        cout << "3. ���������� �������\n";
        cout << "4. �����\n" << endl;
        do {
            cout << "   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if(choice_i >=1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);
        system("cls");
        switch (choice_i) {
        case 1: {
            show_matrix(s);
            system("pause");
            break;
        }
        case 2: {
            edit_matrix(s);
            break;
        }
        case 3: {
            make_paired_calculations(s);
            system("pause");
            break;
        }
        case 4: {
            return;
        }
        default: {
            cout << "\n��������� �����!\n";
            break;
        }
        }

    }
}

//-����� ���������������� ���������-
void menu_succesive_method(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i; 

    while (1) {
        system("cls");

        cout << "\n";
        cout << "     ����� ���������������� ���������" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * \n\n";
        cout << "1. ����������� ��������������� ������\n";
        cout << "2. �������� �������� �����\n";
        cout << "3. ���������� �������\n";
        cout << "4. �����\n" << endl;
        do {
            cout << "   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            system("cls");
            show_estimates(s);
            cout << endl;
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            edit_estimates(s);
            break;
        }
        case 3: {
            make_succesive_calculations(s);
            system("pause");
            break;
        }
        case 4: {
            return;
        }
        default: {
            cout << "\n��������� �����!\n";
            break;
        }
        }

    }
}



bool login_pass_check(string name) {
    bool n = true;
    string k;
    for (int i = 0; name[i] != '\0'; i++) {
        char c = name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || isdigit(c))) {
            n = false;
            break;
        }
    }
    return n;
}


void authentication(SOCKET socket, int who) {
    char buf[255];
    while (1) {
        try {
            system("cls");
            cout << "\n\n\t\t   �����������" << endl;
            cout << "\t* * * * * * * * * * * * * * * * * *" << endl;
            char login[50], password[50];
    
            cout << "\t������� �����: ";
            cin >> login;
            if (!login_pass_check(login))
                throw InputException();
            cout << "\t������� ������: ";
            cin >> password;
            if (!login_pass_check(password))
                throw InputException();
            send(socket, login, sizeof(login), 0);
            send(socket, password, sizeof(password), 0);
            recv(socket, buf, sizeof(buf), 0);
            if (!strcmp(buf, "cool")) {
                cout << "\n\t------����������� ������ �������-----\n";
                Sleep(500);
                who == 1 ? admin_menu(socket) : user_menu(socket);
                break;
            }
            else
                throw ConformityException();
        }
        catch(const ConformityException& exception) {
            cout << "\t" << exception.get_error();
            cout << "\t��������� ����? ������� ������ (n - ���): ";
            char n[2];
            cin >> n;
            send(socket, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << "\t" << exception.get_error();
            Sleep(500);
        }
    }
    return;
}


ostream& setup(ostream& stream) {
    stream.setf(ios::left | ios::fixed);
    stream << setprecision(2);
    return stream;
}


void show_users(SOCKET s) {
    char login[50], password[50], size[10];
    int n;
    recv(s, size, sizeof(size), 0);
    n = atoi(size);

    system("cls");
    cout << "\n\t  ������������\n";
    cout << "-----------------------------------\n";
    cout << "| ID |    �����    |    ������    |\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < n; i++) {
        recv(s, login, sizeof(login), 0);
        recv(s, password, sizeof(password), 0);
        cout << "| " << setup << setw(2) << i + 1 << " | " << setw(11) << login 
            << " | " << setw(12)  << password << " |" << endl;
        cout << "-----------------------------------\n";
    }
}

void add_users(SOCKET s) {
    char login[50], password[50];
    show_users(s);
    while (1) {
        try {
            cout << "\n�����: ";
            cin >> login;
            if (!login_pass_check(login))
                throw InputException();
            cout << "������: ";
            cin >> password;
            if (!login_pass_check(password))
                throw InputException();
            send(s, login, sizeof(login), 0);
            send(s, password, sizeof(password), 0);
            break;
        }
        catch (const InputException& exception) {
            cout << exception.get_error();
        }
    }
    cout << "-------------------------------\n";
    cout << "������������ ��� ������� ��������\n";
    Sleep(1000);
}


void delete_users(SOCKET s) {
    int id;
    char id_char[10], n[2], serv_answer[50];
    show_users(s);
    while (1) {
        try {
            cout << "\n������� ID ������������: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);
            if (!strcmp(serv_answer, "cool")) {
                cout << "-------------------------------\n";
                cout << "������������ � ID " << id << " ��� ������� ������\n";
                Sleep(2000);
                break;
            }
            throw ConformityException();
        }
        catch (const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "��������� ����? ������� ������ (n - ���): ";
            cin >> n;
            send(s, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error() << endl;
        }
    }
}

void edit_users(SOCKET s) {
    int id;
    char id_char[10], n[2], serv_answer[50];
    char new_log_passw[50];
    show_users(s);

    while (1) {
        try {
            cout << "\n������� ID ������������: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);
            if (!strcmp(serv_answer, "cool")) {
                char choice_char[5];
                int choice;

                cout << "\n   �� �� ������ ��������\n";
                cout << "1) �����\n";
                cout << "2) ������\n";
                cout << "   ��� �����: ";
                cin >> choice;
                if (!check(choice) || choice > 2)
                    throw InputException();
                _itoa(choice, choice_char, 10);
                send(s, choice_char, sizeof(choice_char), 0);

                cout << "\n����� ��������: ";
                cin >> new_log_passw;
                if (!login_pass_check(new_log_passw))
                    throw InputException();
                send(s, new_log_passw, sizeof(new_log_passw), 0);
                cout << "-------------------------------\n";
                cout << "������ ������������ � ID " << id << " ������� ��������\n";
                Sleep(2000);
                break;
            }
            else
                throw ConformityException();
        }
        catch(const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "��������� ����? ������� ������ (n - ���): ";
            cin >> n;
            send(s, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error() << endl;
        }
    }
}


void show_segments(SOCKET s) {
    char size[10];
    char name[50], export_percent[10], consumers[10], suppliers[10], rate_of_return[10], roi[10];
    int n;
    recv(s, size, sizeof(size), 0);
    n = atoi(size);

    cout << "\n\t\t\t\t    �������� �����\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "| ID |        ��������        | ������� | ����������� |   ���-��    |   �����   |  ROI  |\n";
    cout << "|    |        ��������        |   (%)   |      (%)    | ����������� |  �������  |       |\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        recv(s, name, sizeof(name), 0);
        recv(s, export_percent, sizeof(export_percent), 0);
        recv(s, consumers, sizeof(consumers), 0);
        recv(s, suppliers, sizeof(suppliers), 0);
        recv(s, rate_of_return, sizeof(rate_of_return), 0);
        recv(s, roi, sizeof(roi), 0);

        cout << "| " << setup << setw(2) << i + 1 << " | " << setw(22) << name
            << " | " << setw(7) << export_percent << " | " << setw(11) << consumers
            << " | " << setw(11) << suppliers << " | " << setw(9) << rate_of_return 
            << " | " << setw(5) << roi << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------\n";
    }
}

void add_segments(SOCKET s) {
    show_segments(s);

    char name[50], export_percent[10], consumers[10], suppliers[10], rate_of_return[10], roi[10];
    int exp, c, suppliers_int, ror, roi_int;
    while (1) {
        try {
            cout << "\n�������� ��������: ";
            cin >> ws;
            cin.getline(name, 50);
            cout << "������� ���������, ������ �� �������: ";
            cin >> exp;
            if (!check(exp))
                throw InputException();
            cout << "������� ������������: ";
            cin >> c;
            if (!check(c))
                throw InputException();
            cout << "���������� �����������: ";
            cin >> suppliers_int;
            if (!check(suppliers_int))
                throw InputException();
            cout << "����� �������: ";
            cin >> ror;
            if (!check(ror))
                throw InputException();
            cout << "�������������� ���������� (ROI): ";
            cin >> roi_int;
            if (!check(roi_int))
                throw InputException();

            send(s, name, sizeof(name), 0);
            _itoa(exp, export_percent, 10);
            send(s, export_percent, sizeof(export_percent), 0);
            _itoa(c, consumers, 10);
            send(s, consumers, sizeof(consumers), 0);
            _itoa(suppliers_int, suppliers, 10);
            send(s, suppliers, sizeof(suppliers), 0);
            _itoa(ror, rate_of_return, 10);
            send(s, rate_of_return, sizeof(rate_of_return), 0);
            _itoa(roi_int, roi, 10);
            send(s, roi, sizeof(roi), 0);
            break;
        }
        catch (const InputException& exception) {
            cout << exception.get_error() << endl;
            cout << "���������� ��� ��� :)";
        }
    }
    cout << "-------------------------------\n";
    cout << "������� ����� ��� ������� ��������\n";
    Sleep(2000);
    system("cls");
    cout << "\n���������� ����� ������ ��������� � ������� �������� ������������!\n";
    show_segments(s);
    cout << endl;
    show_matrix(s);

    char id_new_char[10], value_char[2];
    int id_new, value;
    recv(s, id_new_char, sizeof(id_new_char), 0);
    id_new = atoi(id_new_char);
    cout << "\n������� �������� (1 ��� 0) ��� ��������� ����� �����:\n";

    while(1){
        try {
            for (int i = 1; i < id_new; i++) {
                cout << "matrix [" << id_new << "][" << i << "] = ";
                cin >> value;
                if (value != 1 && value != 0)
                    throw InputException();
                _itoa(value, value_char, 10);
                send(s, value_char, sizeof(value_char), 0);
            }
            break;
        }
        catch (const InputException& exception) {
            cout << exception.get_error() << endl;
        }
    }
    
    cout << "------------------------------------\n";
    cout << "������� ������� ��������\n";
    Sleep(1500);
}


void delete_segments(SOCKET s) {
    int id;
    char id_char[10], n[2], serv_answer[50];
    show_segments(s);

    while (1) {
        try {
            cout << "\n������� ID ��������: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);

            if (!strcmp(serv_answer, "cool")) {
                cout << "-------------------------------\n";
                cout << "������� � ID " << id << " ��� ������� ������\n";
                Sleep(2000);
                break;
            }
            throw ConformityException();
        }
        catch (const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "��������� ����? ������� ������ (n - ���): ";
            cin >> n;
            send(s, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error() << endl;
            cout << "���������� ��� ��� :)";
        }
    }
}



void edit_segments(SOCKET s) {
    int id;
    char id_char[10], n[2], serv_answer[50], new_char_value[50];
    int new_int_value;

    show_segments(s);

    while (1) {
        try {
            cout << "\n������� ID ��������: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);
            if (!strcmp(serv_answer, "cool")) {
                char choice_char[5];
                int choice;

                cout << "\n   �� �� ������ ��������\n";
                cout << "1) �������� ��������\n";
                cout << "2) ������� ��������\n";
                cout << "3) ������� ������������\n";
                cout << "4) ���������� �����������\n";
                cout << "5) ����� �������\n";
                cout << "6) ���������� �� ��������� �������\n";
                cout << "   ��� �����: ";
                cin >> choice;
                if (!check(choice) || choice > 6)
                    throw InputException();
                _itoa(choice, choice_char, 10);
                send(s, choice_char, sizeof(choice_char), 0);

                cout << "\n����� ��������: ";
                if (choice == 1)
                    cin >> new_char_value;
                else {
                    cin >> new_int_value;
                    if (!check(new_int_value))
                        throw InputException();
                    _itoa(new_int_value, new_char_value, 10);
                }
                send(s, new_char_value, sizeof(new_char_value), 0);
                cout << "-------------------------------\n";
                cout << "������ � �������� ����� � ID " << id << " ������� ��������\n";
                Sleep(2000);
                break;
            }
            else
                throw ConformityException();
        }
        catch (const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "��������� ����? ������� ������ (n - ���): ";
            cin >> n;
            send(s, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error() << endl;
            cout << "���������� ��� ��� :)";
        }
    }
}

void show_matrix(SOCKET s) {
    int n;
    char size[5], value_char[10];
    recv(s, size, sizeof(size), 0);
    n = atoi(size);

    vector<vector<int>> matrix(n, vector<int>(n));

    for (auto it = matrix.begin(); it != matrix.end(); it++) {
        for (auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {
            recv(s, value_char, sizeof(value_char), 0);
            *inner_it = atoi(value_char);
        }
    }
    cout << "������� �������� ������������:\n";
    comfort_show(matrix.size());
    cout << "|    |";
    for (int i = 1; i <= n; i++)
        cout << " C" << i << " |";
    cout << endl;
    comfort_show(matrix.size());


    for (unsigned int i = 0; i < matrix.size(); i++) {
        cout << "| " << "C" << i + 1 << " |";
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            if (i == j)
                cout << " -- |";
            else
                cout << " " << setup << setw(2) << matrix[i][j] << " |";
        }
        cout << endl;
        comfort_show(matrix.size());
    }
}


void comfort_show(int n) {
    for (int i = 0; i <= n; i++)
        cout << "-----";
    cout << "-\n";
}

void edit_matrix(SOCKET s) {
    show_matrix(s);
    int i, j, n;
    char size_char[10], i_char[10], j_char[10];
    recv(s, size_char, sizeof(size_char), 0);
    n = atoi(size_char);

    while (1) {
        try {
            cout << "\n����� ������ �� �� ������ ��������?\n";
            cout << "����� ������: ";
            cin >> i;
            if (!check(i) || i > n)
                throw InputException();
            cout << "����� �������: ";
            cin >> j;
            if (!check(j) || j > n || j == i)
                throw InputException();
            _itoa(i, i_char, 10);
            send(s, i_char, sizeof(i_char), 0);
            _itoa(j, j_char, 10);
            send(s, j_char, sizeof(j_char), 0);
           
            cout << "\n-----------------------------------\n";
            cout << "������ ��������� ����� � ID " << i << " � " << j << " ���� ������� ��������\n";
            Sleep(2500);
            break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error();
        }
    }
}

void make_paired_calculations(SOCKET s) {
    char value_char[10], n_char[10], result[30];
    int n;

    recv(s, n_char, sizeof(n_char), 0);
    n = atoi(n_char);

    cout << "���� ������� ��������:\n";

    for(int i = 0; i < n; i++){
        recv(s, value_char, sizeof(value_char), 0);
        cout << "�" << i + 1 << ": " << value_char;
        !((i + 1) % 2) ? cout << endl : cout << "   ";
    }
    cout << "\n\n";

    cout << "��� ������� ��������:\n";
    for (int i = 0; i < n; i++) {
        recv(s, value_char, sizeof(value_char), 0);
        for (unsigned int i = 0; i < strlen(value_char); i++) {
            if (value_char[i] == ',')
                value_char[i] = '.';
        }
        
        cout << "W" << i + 1 << " = " << value_char;
        !((i + 1) % 2) ? cout << endl : cout << "   ";
    }
    cout << "\n\n";

    Sleep(300);
    recv(s, result, sizeof(result), 0);
    cout << "������� ������������ ���������: " << result << endl;
    cout << endl;
}

int show_estimates(SOCKET s) {
    char n_char[10], id_char[10], estimate_char[10];
    int n;

    recv(s, n_char, sizeof(n_char), 0);
    n = atoi(n_char);

    cout << "\n��������������� ������:\n";
    for (int i = 0; i < n; i++) {
        recv(s, id_char, sizeof(id_char), 0);
        recv(s, estimate_char, sizeof(estimate_char), 0);
        cout << "P" << id_char << " = " << estimate_char;
        !((i + 1) % 2) ? cout << endl : cout << "   ";
    }
    cout << endl;
    return n;
}


void edit_estimates(SOCKET s) {
    char id_char[10], estimate_char[10], serv_answer[50], ch[2];
    int id, estimate, n;
    show_segments(s);
    n = show_estimates(s);

    while (1) {
        try {
            cout << "\n������� ID �������� ��� ��������� ������: ";
            cin >> id;
            if (!check(id) || id > n)
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);

            while (1) {
                try {
                    cout << "����� ������: ";
                    cin >> estimate;
                    if (!check(estimate))
                        throw InputException();
                    _itoa(estimate, estimate_char, 10);
                    send(s, estimate_char, sizeof(estimate_char), 0);
                    Sleep(500);
                    recv(s, serv_answer, sizeof(serv_answer), 0);

                    if (!strcmp(serv_answer, "cool")) {
                        cout << "-------------------------------\n";
                        cout << "������ �������� � ID " << id << " ���� ������� ��������\n";
                        system("pause");
                        break;
                    }
                    throw ConformityException();
                }
                catch (const ConformityException& exception) {
                    cout << "������ �� ������ �������� �� �������� ��������� ���������!\n" << endl;
                    cout << "��������� ����? ������� ������ (n - ���): ";
                    cin >> ch;
                    send(s, ch, sizeof(ch), 0);
                    if (!strcmp(ch, "n"))
                        break;
                }
                catch (const Exception& exception) {
                    cout << exception.get_error() << endl;
                }
            }
            break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error();
        }
    }
}

void make_succesive_calculations(SOCKET s) {
    char value_char[10], n_char[10], result[30];
    int n;

    recv(s, n_char, sizeof(n_char), 0);
    n = atoi(n_char);

    system("cls");
    cout << "��� ������� ��������:\n";
    for (int i = 0; i < n; i++) {
        recv(s, value_char, sizeof(value_char), 0);
        for (unsigned int i = 0; i < strlen(value_char); i++) {
            if (value_char[i] == ',')
                value_char[i] = '.';
        }

        cout << "W" << i + 1 << " = " << value_char;
        !((i + 1) % 2) ? cout << endl : cout << "   ";
    }
    cout << "\n\n";

    Sleep(300);
    recv(s, result, sizeof(result), 0);
    cout << "�������� ������� ������������ ���������: " << result << endl;
    cout << endl;
}

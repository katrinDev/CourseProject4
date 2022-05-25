#include "myLib_c1.h"

void main_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;
    while (1) {
        system("cls");

        cout << "\n\n";
        cout << "\t\t   Авторизация" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * \n\n";
        cout << "\t1. Войти под администратором\n";
        cout << "\t2. Войти под пользователем\n";
        cout << "\t3. Выход\n" << endl;
        do {
            cout << "\t   Ваш выбор: ";
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
            cout << "\n\tОшибочный выбор!\n";
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
        cout << "\tМеню администратора\n";
        cout << "* * * * * * * * * * * * * * * * * *\n";
        cout << "1. Просмотреть данные о сегментах рынка в табличной форме\n";
        cout << "2. Метод парных сравнений\n";
        cout << "3. Метод последовательных сравнений\n";
        cout << "4. Добавить сегмент\n";
        cout << "5. Редактировать данные о сегментах\n";
        cout << "6. Удалить сегмент из списка\n";
        cout << "7. Управление пользователями\n";
        cout << "8. Завершить работу\n\n";
        do {
            cout << "   Ваш выбор: ";
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
                cout << "\nНеобходимы данные из расчетов метода парных сравнений!\n";
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
            cout << "\nОшибочный выбор!\n";
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
        cout << "\t Меню пользователя\n";
        cout << "* * * * * * * * * * * * * * * * * * *\n";
        cout << "1. Просмотреть данные в табличной форме\n";
        cout << "2. Метод парных сравнений\n";
        cout << "3. Метод последовательных сравнений\n";
        cout << "4. Завершить работу\n";
        do {
            cout << "   Ваш выбор: ";
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
            cout << "\nОшибочный выбор!\n";
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
        cout << "\tМеню управления пользователями" << endl;
        cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1. Просмотреть данные в табличной форме" << endl;
        cout << "2. Добавить пользователя" << endl;
        cout << "3. Удалить пользователя" << endl;
        cout << "4. Редактировать данные пользователя" << endl;
        cout << "5. Выход в меню администратора\n" << endl;
        do {
            cout << "   Ваш выбор: ";
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
            cout << "\nОшибочный выбор!\n";
            break;
        }
        }
    }
}

//-МЕТОД ПАРНЫХ СРАВНЕНИЙ-
void menu_paired_method(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (1) {
        system("cls");

        cout << "\n";
        cout << "\t   Метод парных сравнений" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * *\n\n";
        cout << "1. Просмотреть матрицу бинарных предпочтений\n";
        cout << "2. Редактировать матрицу\n";
        cout << "3. Произвести расчеты\n";
        cout << "4. Выход\n" << endl;
        do {
            cout << "   Ваш выбор: ";
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
            cout << "\nОшибочный выбор!\n";
            break;
        }
        }

    }
}

//-МЕТОД ПОСЛЕДОВАТЕЛЬНЫХ СРАВНЕНИЙ-
void menu_succesive_method(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i; 

    while (1) {
        system("cls");

        cout << "\n";
        cout << "     Метод последовательных сравнений" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * \n\n";
        cout << "1. Просмотреть предварительные оценки\n";
        cout << "2. Сравнить сегменты рынка\n";
        cout << "3. Произвести расчеты\n";
        cout << "4. Выход\n" << endl;
        do {
            cout << "   Ваш выбор: ";
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
            cout << "\nОшибочный выбор!\n";
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
            cout << "\n\n\t\t   Авторизация" << endl;
            cout << "\t* * * * * * * * * * * * * * * * * *" << endl;
            char login[50], password[50];
    
            cout << "\tВведите логин: ";
            cin >> login;
            if (!login_pass_check(login))
                throw InputException();
            cout << "\tВведите пароль: ";
            cin >> password;
            if (!login_pass_check(password))
                throw InputException();
            send(socket, login, sizeof(login), 0);
            send(socket, password, sizeof(password), 0);
            recv(socket, buf, sizeof(buf), 0);
            if (!strcmp(buf, "cool")) {
                cout << "\n\t------Авторизация прошла успешно-----\n";
                Sleep(500);
                who == 1 ? admin_menu(socket) : user_menu(socket);
                break;
            }
            else
                throw ConformityException();
        }
        catch(const ConformityException& exception) {
            cout << "\t" << exception.get_error();
            cout << "\tПовторный ввод? Введите символ (n - нет): ";
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
    cout << "\n\t  Пользователи\n";
    cout << "-----------------------------------\n";
    cout << "| ID |    Логин    |    Пароль    |\n";
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
            cout << "\nЛогин: ";
            cin >> login;
            if (!login_pass_check(login))
                throw InputException();
            cout << "Пароль: ";
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
    cout << "Пользователь был успешно добавлен\n";
    Sleep(1000);
}


void delete_users(SOCKET s) {
    int id;
    char id_char[10], n[2], serv_answer[50];
    show_users(s);
    while (1) {
        try {
            cout << "\nВведите ID пользователя: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);
            if (!strcmp(serv_answer, "cool")) {
                cout << "-------------------------------\n";
                cout << "Пользователь с ID " << id << " был успешно удален\n";
                Sleep(2000);
                break;
            }
            throw ConformityException();
        }
        catch (const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "Повторный ввод? Введите символ (n - нет): ";
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
            cout << "\nВведите ID пользователя: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);
            if (!strcmp(serv_answer, "cool")) {
                char choice_char[5];
                int choice;

                cout << "\n   Вы бы хотели изменить\n";
                cout << "1) Логин\n";
                cout << "2) Пароль\n";
                cout << "   Ваш выбор: ";
                cin >> choice;
                if (!check(choice) || choice > 2)
                    throw InputException();
                _itoa(choice, choice_char, 10);
                send(s, choice_char, sizeof(choice_char), 0);

                cout << "\nНовое значение: ";
                cin >> new_log_passw;
                if (!login_pass_check(new_log_passw))
                    throw InputException();
                send(s, new_log_passw, sizeof(new_log_passw), 0);
                cout << "-------------------------------\n";
                cout << "Данные пользователя с ID " << id << " успешно изменены\n";
                Sleep(2000);
                break;
            }
            else
                throw ConformityException();
        }
        catch(const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "Повторный ввод? Введите символ (n - нет): ";
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

    cout << "\n\t\t\t\t    Сегменты рынка\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "| ID |        Название        | Экспорт | Потребители |   Кол-во    |   Норма   |  ROI  |\n";
    cout << "|    |        сегмента        |   (%)   |      (%)    | поставщиков |  прибыли  |       |\n";
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
            cout << "\nНазвание сегмента: ";
            cin >> ws;
            cin.getline(name, 50);
            cout << "Процент продукции, идущий на экспорт: ";
            cin >> exp;
            if (!check(exp))
                throw InputException();
            cout << "Процент потребителей: ";
            cin >> c;
            if (!check(c))
                throw InputException();
            cout << "Количество поставщиков: ";
            cin >> suppliers_int;
            if (!check(suppliers_int))
                throw InputException();
            cout << "Норма прибыли: ";
            cin >> ror;
            if (!check(ror))
                throw InputException();
            cout << "Рентабельность инвестиций (ROI): ";
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
            cout << "Попробуйте еще раз :)";
        }
    }
    cout << "-------------------------------\n";
    cout << "Сегмент рынка был успешно добавлен\n";
    Sleep(2000);
    system("cls");
    cout << "\nНеобходимо также внести изменения в матрицу бинарных предпочтений!\n";
    show_segments(s);
    cout << endl;
    show_matrix(s);

    char id_new_char[10], value_char[2];
    int id_new, value;
    recv(s, id_new_char, sizeof(id_new_char), 0);
    id_new = atoi(id_new_char);
    cout << "\nВведите значения (1 или 0) для следующих новых ячеек:\n";

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
    cout << "Матрица успешно изменена\n";
    Sleep(1500);
}


void delete_segments(SOCKET s) {
    int id;
    char id_char[10], n[2], serv_answer[50];
    show_segments(s);

    while (1) {
        try {
            cout << "\nВведите ID сегмента: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);

            if (!strcmp(serv_answer, "cool")) {
                cout << "-------------------------------\n";
                cout << "Сегмент с ID " << id << " был успешно удален\n";
                Sleep(2000);
                break;
            }
            throw ConformityException();
        }
        catch (const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "Повторный ввод? Введите символ (n - нет): ";
            cin >> n;
            send(s, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error() << endl;
            cout << "Попробуйте еще раз :)";
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
            cout << "\nВведите ID сегмента: ";
            cin >> id;
            if (!check(id))
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);
            recv(s, serv_answer, sizeof(serv_answer), 0);
            if (!strcmp(serv_answer, "cool")) {
                char choice_char[5];
                int choice;

                cout << "\n   Вы бы хотели изменить\n";
                cout << "1) Название сегмента\n";
                cout << "2) Процент экспорта\n";
                cout << "3) Процент потребителей\n";
                cout << "4) Количество поставщиков\n";
                cout << "5) Норму прибыли\n";
                cout << "6) Доходность на вложенный капитал\n";
                cout << "   Ваш выбор: ";
                cin >> choice;
                if (!check(choice) || choice > 6)
                    throw InputException();
                _itoa(choice, choice_char, 10);
                send(s, choice_char, sizeof(choice_char), 0);

                cout << "\nНовое значение: ";
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
                cout << "Данные о сегменте рынка с ID " << id << " успешно изменены\n";
                Sleep(2000);
                break;
            }
            else
                throw ConformityException();
        }
        catch (const ConformityException& exception) {
            cout << exception.get_error() << endl;
            cout << "Повторный ввод? Введите символ (n - нет): ";
            cin >> n;
            send(s, n, sizeof(n), 0);
            if (!strcmp(n, "n"))
                break;
        }
        catch (const Exception& exception) {
            cout << exception.get_error() << endl;
            cout << "Попробуйте еще раз :)";
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
    cout << "Матрица бинарных предпочтений:\n";
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
            cout << "\nКакую оценку вы бы хотели изменить?\n";
            cout << "Номер строки: ";
            cin >> i;
            if (!check(i) || i > n)
                throw InputException();
            cout << "Номер столбца: ";
            cin >> j;
            if (!check(j) || j > n || j == i)
                throw InputException();
            _itoa(i, i_char, 10);
            send(s, i_char, sizeof(i_char), 0);
            _itoa(j, j_char, 10);
            send(s, j_char, sizeof(j_char), 0);
           
            cout << "\n-----------------------------------\n";
            cout << "Оценки сегментов рынка с ID " << i << " и " << j << " были успешно изменены\n";
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

    cout << "Цена каждого сегмента:\n";

    for(int i = 0; i < n; i++){
        recv(s, value_char, sizeof(value_char), 0);
        cout << "С" << i + 1 << ": " << value_char;
        !((i + 1) % 2) ? cout << endl : cout << "   ";
    }
    cout << "\n\n";

    cout << "Вес каждого сегмента:\n";
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
    cout << "Порядок предпочтения сегментов: " << result << endl;
    cout << endl;
}

int show_estimates(SOCKET s) {
    char n_char[10], id_char[10], estimate_char[10];
    int n;

    recv(s, n_char, sizeof(n_char), 0);
    n = atoi(n_char);

    cout << "\nПредварительные оценки:\n";
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
            cout << "\nВведите ID сегмента для изменения оценки: ";
            cin >> id;
            if (!check(id) || id > n)
                throw InputException();
            _itoa(id, id_char, 10);
            send(s, id_char, sizeof(id_char), 0);

            while (1) {
                try {
                    cout << "Новая оценка: ";
                    cin >> estimate;
                    if (!check(estimate))
                        throw InputException();
                    _itoa(estimate, estimate_char, 10);
                    send(s, estimate_char, sizeof(estimate_char), 0);
                    Sleep(500);
                    recv(s, serv_answer, sizeof(serv_answer), 0);

                    if (!strcmp(serv_answer, "cool")) {
                        cout << "-------------------------------\n";
                        cout << "Оценка сегмента с ID " << id << " была успешно изменена\n";
                        system("pause");
                        break;
                    }
                    throw ConformityException();
                }
                catch (const ConformityException& exception) {
                    cout << "Оценка не должна выходить за значения ближайших сегментов!\n" << endl;
                    cout << "Повторный ввод? Введите символ (n - нет): ";
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
    cout << "Вес каждого сегмента:\n";
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
    cout << "Итоговый порядок предпочтения сегментов: " << result << endl;
    cout << endl;
}

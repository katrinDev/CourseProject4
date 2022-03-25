#include "myLib_c1.h"


void main_menu(SOCKET s) {
    char choice[200];
    while (1) {
        system("cls");

        cout << "\n\n";
        cout << "\t\t   Авторизация" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * \n\n";
        cout << "\t1. Войти под администратором\n";
        cout << "\t2. Войти под пользователем\n";
        cout << "\t3. Выход\n" << endl;
        cout << "\t   Ваш выбор: ";
        cin >> choice;
        int choice_i = atoi(choice);
        //проверка int
        send(s, choice, sizeof(choice), 0);

        //если авторизация пройдена
        switch (choice[0]){
        case '1': {
            admin_menu(s);
            break;
        }
        case '2': {
            user_menu(s);
            break;
        }
        case '3': {
            return;
        }
        default: {
            cout << "Ошибочный выбор!\n";
            break;
        }
        }
        
    }
}


void admin_menu(SOCKET s) {
    char choice[50];

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
        cout << "   Ваш выбор: ";
        cin >> choice;
        int choice_i = atoi(choice);
        //проверка int
        send(s, choice, sizeof(choice), 0);

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
        default: {
            cout << "Ошибочный выбор!\n";
            break;
        }
        }

    }
}

void user_menu(SOCKET s) {
    char choice[50];

    while (true) {
        system("cls");
        cout << "\n";
        cout << "\t Меню пользователя\n";
        cout << "* * * * * * * * * * * * * * * * * * *\n";
        cout << "1. Просмотреть данные в табличной форме\n";
        cout << "2. Метод парных сравнений\n";
        cout << "3. Метод последовательных сравнений\n";
        cout << "4. Завершить работу\n";
        cout << "   Ваш выбор: ";
        cin >> choice;
        int choice_i = atoi(choice);
        //проверка int
        send(s, choice, sizeof(choice), 0);

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
         default: {
             cout << "Ошибочный выбор!\n";
             break;
         }
         }
    }
}



template <class T>
int check(T num) {//шаблонная функции
    int k = 1;
    if (cin.fail()) {
        k = 0;
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Вы можете использовать только числа!\n";
    }
    if (k == 1 && num <= 0) {
        cout << "Вы можете использовать только положительные числа!\n";
        k = 0;
    }
    return k;
}
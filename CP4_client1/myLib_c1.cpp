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

        //если авторизация пройдена
        switch (choice_i){
        case 1: {
            admin_menu(s);
            break;
        }
        case 2: {
            user_menu(s);
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
            cout << "\t   Ваш выбор: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if(choice_i >=1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            cout << "\nМатрица бинарных предпочтений\n";
            break;
        }
        case 2: {
            cout << "\nРедактировать матрицу\n";
            break;
        }
        case 3: {
            cout << "\nПроизвести расчеты\n";
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
        cout << "\tМетод последовательных сравнений" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * \n\n";
        cout << "1. Редактировать предварительные оценки\n";
        cout << "2. Сравнить сегменты рынка\n";
        cout << "3. Произвести расчеты\n";
        cout << "4. Выход\n" << endl;
        do {
            cout << "\t   Ваш выбор: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            cout << "\nРедактировать предварительные оценки\n";
            break;
        }
        case 2: {
            cout << "\nСравнить сегменты рынка\n";

            break;
        }
        case 3: {
            cout << "\nПроизвести расчеты\n";
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
            cout << "\t   Ваш выбор: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 8)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            cout << "\nПросмотреть данные о сегментах рынка в табличной форме\n";
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
            cout << "\nДобавить сегмент\n";

            break;
        }
        case 5: {
            cout << "\nРедактировать данные о сегментах\n";
            break;
        }
        case 6: {
            cout << "\nУдалить сегмент из списка\n";
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

void user_manage_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (true) {
        system("cls");
        cout << "\n";
        cout << "\tМеню управления пользователями" << endl;
        cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1. Добавить пользователя" << endl;
        cout << "2. Редактировать данные пользователя" << endl;
        cout << "3. Удалить пользователя" << endl;
        cout << "4. Просмотреть данные в табличной форме" << endl;
        cout << "5. Выход в меню администратора\n" << endl;
        do {
            cout << "\t   Ваш выбор: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 5)
            send(s, choice, sizeof(choice), 0);


        switch (choice_i) {
        case 1: {
            cout << "\nДобавить пользователя\n";
            break;
        }
        case 2: {
            cout << "\nРедактировать данные пользователя\n";
            break;
        }
        case 3: {
            cout << "\nУдалить пользователя\n";
            break;
        }
        case 4: {
            cout << "\nПросмотреть данные в табличной форме\n";
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
            cout << "\t   Ваш выбор: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

         switch (choice_i) {
         case 1: {
             cout << "\nПросмотреть данные в табличной форме\n";
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
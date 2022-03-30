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

        //���� ����������� ��������
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
            cout << "\n\t��������� �����!\n";
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
            cout << "\t   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if(choice_i >=1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            cout << "\n������� �������� ������������\n";
            break;
        }
        case 2: {
            cout << "\n������������� �������\n";
            break;
        }
        case 3: {
            cout << "\n���������� �������\n";
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
        cout << "\t����� ���������������� ���������" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * \n\n";
        cout << "1. ������������� ��������������� ������\n";
        cout << "2. �������� �������� �����\n";
        cout << "3. ���������� �������\n";
        cout << "4. �����\n" << endl;
        do {
            cout << "\t   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            cout << "\n������������� ��������������� ������\n";
            break;
        }
        case 2: {
            cout << "\n�������� �������� �����\n";

            break;
        }
        case 3: {
            cout << "\n���������� �������\n";
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
            cout << "\t   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 8)
            send(s, choice, sizeof(choice), 0);

        switch (choice_i) {
        case 1: {
            cout << "\n����������� ������ � ��������� ����� � ��������� �����\n";
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
            cout << "\n�������� �������\n";

            break;
        }
        case 5: {
            cout << "\n������������� ������ � ���������\n";
            break;
        }
        case 6: {
            cout << "\n������� ������� �� ������\n";
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

void user_manage_menu(SOCKET s) {
    char choice[50];
    bool flag;
    int choice_i;

    while (true) {
        system("cls");
        cout << "\n";
        cout << "\t���� ���������� ��������������" << endl;
        cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1. �������� ������������" << endl;
        cout << "2. ������������� ������ ������������" << endl;
        cout << "3. ������� ������������" << endl;
        cout << "4. ����������� ������ � ��������� �����" << endl;
        cout << "5. ����� � ���� ��������������\n" << endl;
        do {
            cout << "\t   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 5)
            send(s, choice, sizeof(choice), 0);


        switch (choice_i) {
        case 1: {
            cout << "\n�������� ������������\n";
            break;
        }
        case 2: {
            cout << "\n������������� ������ ������������\n";
            break;
        }
        case 3: {
            cout << "\n������� ������������\n";
            break;
        }
        case 4: {
            cout << "\n����������� ������ � ��������� �����\n";
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
            cout << "\t   ��� �����: ";
            cin >> choice;
            choice_i = atoi(choice);
            flag = check(choice_i);
        } while (!flag);

        if (choice_i >= 1 && choice_i <= 4)
            send(s, choice, sizeof(choice), 0);

         switch (choice_i) {
         case 1: {
             cout << "\n����������� ������ � ��������� �����\n";
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



template <class T>
int check(T num) {//��������� �������
    int k = 1;
    if (cin.fail()) {
        k = 0;
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "�� ������ ������������ ������ �����!\n";
    }
    if (k == 1 && num <= 0) {
        cout << "�� ������ ������������ ������ ������������� �����!\n";
        k = 0;
    }
    return k;
}
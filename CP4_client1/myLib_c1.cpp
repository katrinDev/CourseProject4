#include "myLib_c1.h"


void main_menu(SOCKET s) {
    char choice[200];
    while (1) {
        system("cls");

        cout << "\n\n";
        cout << "\t\t   �����������" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * \n\n";
        cout << "\t1. ����� ��� ���������������\n";
        cout << "\t2. ����� ��� �������������\n";
        cout << "\t3. �����\n" << endl;
        cout << "\t   ��� �����: ";
        cin >> choice;
        int choice_i = atoi(choice);
        //�������� int
        send(s, choice, sizeof(choice), 0);

        //���� ����������� ��������
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
            cout << "��������� �����!\n";
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
        cout << "   ��� �����: ";
        cin >> choice;
        int choice_i = atoi(choice);
        //�������� int
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
            cout << "��������� �����!\n";
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
        cout << "\t ���� ������������\n";
        cout << "* * * * * * * * * * * * * * * * * * *\n";
        cout << "1. ����������� ������ � ��������� �����\n";
        cout << "2. ����� ������ ���������\n";
        cout << "3. ����� ���������������� ���������\n";
        cout << "4. ��������� ������\n";
        cout << "   ��� �����: ";
        cin >> choice;
        int choice_i = atoi(choice);
        //�������� int
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
             cout << "��������� �����!\n";
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
#include "Game.h"


int tempMap[20][30]; //�ӽ����� �迭
int correct = 0;




int KeyControl() {
    char temp = _getch();

    switch (temp)
    {
    case 'w':
    case 'a':
        return UP;
        break;
    case 's':
    case 'd':
        return DOWN;
        break;
    case ' ':
        return SUBMIT;
        break;
    default:
        return (int)temp;
        break;
    }
}

//

int MenuDraw() {
    int x = (WIDTH / 2) - 2;
    int y = HEIGHT / 2;
    int temp = y;

    Gotoxy(x - 1, temp);
    cout << "> ���ӽ���";
    Gotoxy(x, temp + 1);
    cout << "��������";
    Gotoxy(x, temp + 2);
    cout << "����";

    while (1) {
        int n = KeyControl();
        switch (n) {
        case UP: {
            if (temp > y) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, --temp);
                cout << ">";
                
            }
            break;
        }
        case DOWN: {
            if (temp < y+2) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, ++temp);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return temp - y;
        }
        }
    }
}

void TitleDraw() {
    Gotoxy(10, 10);
    cout << "������ �������� ����" << endl;
    Gotoxy(10, 11);
    cout << "wasd�� �̵�, space�� ����" << endl;

}

void InfoDraw() {
    system("cls");

    cout << "������ �������� �����Դϴ�." << endl;
    cout << "��� ���⿡�� ���ƿ��� ���� ���������� �е带 �̵��ϸ� ƨ�ܳ��� �˴ϴ�." << endl;
    cout << "����� ���� ������ �μ��� ���� ������ŭ ���� ��ġ���� ������˴ϴ�." << endl << endl;
    cout << "������ ��� ����� ������ �ܼ� ȭ���� ���� Ȯ�� �����մϴ�." << endl;

    cout << "200���� �޼��ϸ� �¸��մϴ�." << endl;
    cout << "������ ���̳ʽ��� �Ǹ� �й��մϴ�." << endl;
    cout << "����� �μ��� +1���Դϴ�." << endl;
    cout << "���� ȭ�� �����ڸ��� ���� line�� ������ �����Դϴ�." << endl << endl;
    cout << "���� ������ ���̵��� ���� �ٸ��ϴ�. (7/6/6)" << endl;
    cout << "�ʱ� ������ 70/70/100���Դϴ�." << endl;
    cout << "���̵��� ���� �� ����, �ʱ� ����, ���� ������, ����� ��� ���� ���� �޶����ϴ�." << endl<<endl;

    cout << "w/s: Ŀ���� ��/�Ʒ��� �����̰ų� " << endl;
    cout << "��/���� �е带 ��/�Ʒ��� �̵�" << endl;
    cout << "a/d: Ŀ���� ��/�Ʒ��� �����̰ų� " << endl;
    cout << "��/���� �е带 �¿�� �̵�" <<endl;
    cout << "space: ����" << endl;



    while (1) {
        if ((KeyControl() == SUBMIT) || (KeyControl() == EXIT)) {
            break;
        }
    }
}

int MaplistDraw() {
    system("cls");
    int x = (WIDTH / 2) - 2;
    int y = HEIGHT / 2;
    int temp = y;

    Gotoxy(x - 1, temp);
    cout << "> ����";
    Gotoxy(x, temp + 1);
    cout << "����";
    Gotoxy(x, temp + 2);
    cout << "�����";
    Gotoxy(x, temp + 3);
    cout << "�ڷ�";
    Gotoxy(x, temp);


    while (1) {
        int n = KeyControl();
        switch (n) {
        case UP: {
            if (temp > y) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, --temp);
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (temp < y+3) {
                Gotoxy(x - 1, temp);
                cout << " ";
                Gotoxy(x - 1, ++temp);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return temp - y;
        }

        }
    }
}

//





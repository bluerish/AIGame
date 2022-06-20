#include "Game.h"


int tempMap[20][30]; //임시저장 배열
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
    cout << "> 게임시작";
    Gotoxy(x, temp + 1);
    cout << "게임정보";
    Gotoxy(x, temp + 2);
    cout << "종료";

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
    cout << "전방향 벽돌깨기 게임" << endl;
    Gotoxy(10, 11);
    cout << "wasd로 이동, space로 선택" << endl;

}

void InfoDraw() {
    system("cls");

    cout << "전방향 벽돌깨기 게임입니다." << endl;
    cout << "모든 방향에서 날아오는 공을 동서남북의 패드를 이동하며 튕겨내면 됩니다." << endl;
    cout << "블록은 일정 개수를 부수면 같은 개수만큼 랜덤 위치에서 재생성됩니다." << endl << endl;
    cout << "점수와 블록 재생성 시점은 콘솔 화면을 통해 확인 가능합니다." << endl;

    cout << "200점을 달성하면 승리합니다." << endl;
    cout << "점수가 마이너스가 되면 패배합니다." << endl;
    cout << "블록을 부수면 +1점입니다." << endl;
    cout << "공이 화면 가장자리의 붉은 line에 닿으면 감점입니다." << endl << endl;
    cout << "감점 점수는 난이도에 따라 다릅니다. (7/6/6)" << endl;
    cout << "초기 점수는 70/70/100점입니다." << endl;
    cout << "난이도에 따라 공 개수, 초기 점수, 라인 감점값, 재생성 블록 개수 등이 달라집니다." << endl<<endl;

    cout << "w/s: 커서를 위/아래로 움직이거나 " << endl;
    cout << "동/서의 패드를 위/아래로 이동" << endl;
    cout << "a/d: 커서를 위/아래로 움직이거나 " << endl;
    cout << "남/북의 패드를 좌우로 이동" <<endl;
    cout << "space: 결정" << endl;



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
    cout << "> 쉬움";
    Gotoxy(x, temp + 1);
    cout << "보통";
    Gotoxy(x, temp + 2);
    cout << "어려움";
    Gotoxy(x, temp + 3);
    cout << "뒤로";
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





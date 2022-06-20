
#include "Tools.h"



void Init() {
    system("mode con cols=60 lines=30");
    system("title AAA");


    //커서 제거
    CursorVisible(0);
}



void Gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 2 * x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void CursorVisible(int visible) {

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = visible;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
#pragma once
#include"Tools.h"
#include <iostream>
#include <conio.h>
#include <random>
using namespace std;

enum { UP, DOWN, EXIT, SUBMIT };
const int WIDTH = 30;
const int HEIGHT = 30;

int KeyControl();

void TitleDraw();
int MenuDraw();
void InfoDraw();
int MaplistDraw();





#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>

#define MAX_POINTER_SIZE 6

#define CANVAS_X 79
#define CANVAS_Y 24

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_PLUS 43
#define KEY_MINUS 45

//#define KEY_ENTER 13
//#define KEY_SPACE 32
#define KEY_ESC 27


struct pointer {
	char pointer_symbol;
	int pointer_size;
};

struct position {
	int x = 45;
	int y = 5;
};

pointer start_page();
void keybord_listener(position position, pointer pointer);
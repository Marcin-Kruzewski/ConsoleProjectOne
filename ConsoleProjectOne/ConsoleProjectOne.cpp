// ConsoleProjectOne.cpp : Defines the entry point for the console application.
//

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

#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESC 27


struct pointer {
	char pointer_symbol;
	int pointer_size;
};

struct position {
	int x = 45;
	int y = 5;
};

using namespace std;

pointer start_page()
{
	system("cls");
	printf(
		"*******************************************************************************\n"
		"*                                                                             *\n"
		"*  Welcome in my Project. You can change position of POINTER with arrow keys. *\n"
		"*  You can change POINTER's size with '+' and '-' keys.                       *\n"
		"*                                                                             *\n"
		"*  But first you have to chose ASCII symbol to draw POINTER with.             *\n"
		"*                           And it's initial size from range <1; 6>.          *\n"
		"*                                                                             *\n"
		"*                                                    PRG1 - Project nr 69     *\n"
		"*                                                    Marcin Kruzewski s13927  *\n"
		"*                                                                             *\n"
		"*******************************************************************************\n");
	pointer pointer;
	cout << "POINTER's size: ";
	cin >> pointer.pointer_size;
	cout << "POINTER's symbol: ";
	cin >> pointer.pointer_symbol;
	return pointer;
}

void print_display(char display[CANVAS_X][CANVAS_Y])
{
	for (int i = 0; i < CANVAS_Y; i++)
	{
		for (int j = 0; j < CANVAS_X; j++)
		{
			cout << display[j][i];
		}
		cout << endl;
	}
}

void draw_display(pointer pointer, position position)
{
	char display[CANVAS_X][CANVAS_Y];
	for (int i = 0; i < CANVAS_X; i++)
	{
		for (int j = 0; j < CANVAS_Y; j++)
		{
			display[i][j] = ' ';
		}
	}
	for (int i = 0; i < CANVAS_X; i++)
	{
		display[i][0] = pointer.pointer_symbol;
		display[i][CANVAS_Y - 1] = pointer.pointer_symbol;
	}
	for (int i = 0; i < CANVAS_Y; i++)
	{
		display[0][i] = pointer.pointer_symbol;
		display[CANVAS_X - 1][i] = pointer.pointer_symbol;
	}
	display[position.x][position.y] = pointer.pointer_symbol;
	switch (pointer.pointer_size)
	{
	case 1:
		display[position.x - 1][position.y + 1] = 'X';
		break;
	case 2:
		display[position.x - 1][position.y + 1] = '/';
		display[position.x - 2][position.y + 1] = '\\';
		display[position.x - 1][position.y + 2] = '\\';
		display[position.x - 2][position.y + 2] = '/';
		break;
	case 3:
		display[position.x - 1][position.y + 1] = '/';
		display[position.x - 1][position.y + 3] = '\\';
		display[position.x - 2][position.y + 2] = 'X';
		display[position.x - 3][position.y + 1] = '\\';
		display[position.x - 3][position.y + 3] = '/';
		break;
	case 4:
		display[position.x - 1][position.y + 1] = '/';
		display[position.x - 2][position.y + 2] = '/';
		display[position.x - 3][position.y + 3] = '/';
		display[position.x - 4][position.y + 4] = '/';
		display[position.x - 1][position.y + 4] = '\\';
		display[position.x - 2][position.y + 3] = '\\';
		display[position.x - 3][position.y + 2] = '\\';
		display[position.x - 4][position.y + 1] = '\\';
		break;
	case 5:
		display[position.x - 1][position.y + 1] = '/';
		display[position.x - 2][position.y + 2] = '/';
		display[position.x - 3][position.y + 3] = 'X';
		display[position.x - 4][position.y + 4] = '/';
		display[position.x - 5][position.y + 5] = '/';
		display[position.x - 1][position.y + 5] = '\\';
		display[position.x - 2][position.y + 4] = '\\';
		display[position.x - 4][position.y + 2] = '\\';
		display[position.x - 5][position.y + 1] = '\\';
		break;
	case 6:
		display[position.x - 1][position.y + 1] = '/';
		display[position.x - 2][position.y + 2] = '/';
		display[position.x - 3][position.y + 3] = '/';
		display[position.x - 4][position.y + 4] = '/';
		display[position.x - 5][position.y + 5] = '/';
		display[position.x - 6][position.y + 6] = '/';
		display[position.x - 1][position.y + 6] = '\\';
		display[position.x - 2][position.y + 5] = '\\';
		display[position.x - 3][position.y + 4] = '\\';
		display[position.x - 4][position.y + 3] = '\\';
		display[position.x - 5][position.y + 2] = '\\';
		display[position.x - 6][position.y + 1] = '\\';
		break;
	default:
		break;
	}
	system("cls");
	print_display(display);
}

position move_up(position position)
{
	if (position.y > 1) position.y--;
	return position;
}

position move_down(position position, int size)
{
	if (position.y < CANVAS_Y - size - 2) position.y++;
	return position;
}

position move_left(position position, int size)
{
	if (position.x > 1 + size) position.x--;
	return position;
}

position move_right(position position)
{
	if (position.x < CANVAS_X - 2) position.x++;
	return position;
}

pointer size_down(pointer pointer)
{
	if (pointer.pointer_size > 1) pointer.pointer_size--;
	return pointer;
}

pointer size_up(pointer pointer, position position)
{
	if (position.x > 1 + pointer.pointer_size)
	{
		if (position.y < CANVAS_Y - pointer.pointer_size - 2)
		{
			if (pointer.pointer_size < MAX_POINTER_SIZE) pointer.pointer_size++;
		}
	}
	return pointer;
}

void keybord_listener(position position, pointer pointer)
{
	char pressed_key = '\0';
	bool continuation = true;
	while (continuation)
	{
		draw_display(pointer, position);
		pressed_key = _getch();
		switch (pressed_key)
		{
		case KEY_UP:
			position = move_up(position);
			break;
		case KEY_DOWN:
			position = move_down(position, pointer.pointer_size);
			break;
		case KEY_RIGHT:
			position = move_right(position);
			break;
		case KEY_LEFT:
			position = move_left(position, pointer.pointer_size);
			break;
		case KEY_MINUS:
			pointer = size_down(pointer);
			break;
		case KEY_PLUS:
			pointer = size_up(pointer, position);
			break;
		case KEY_ESC:
			continuation = false;
			break;
		default:
			break;
		}
	}
}


int main()
{
	pointer pointer = start_page();
	position position;
	keybord_listener(position, pointer);
	return 0;
}

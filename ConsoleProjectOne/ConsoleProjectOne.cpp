// ConsoleProjectOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pointer.h"

int main()
{
	pointer pointer = start_page();
	position position;
	keybord_listener(position, pointer);
	return 0;
}

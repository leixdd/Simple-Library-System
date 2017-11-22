#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info;
COORD coord;
WORD color;

int loadscreenx;

void ChangeForetextColor(int num, BOOL intensity){
	switch (num){

	case 1:		/* Green */ color = FOREGROUND_GREEN; break;
	case 2:		/* Red   */ color = FOREGROUND_RED; break;
	case 3:		/* Blue  */ color = FOREGROUND_BLUE; break;
	case 4:		/* CYAN  */ color = FOREGROUND_GREEN | FOREGROUND_BLUE; break;
	case 5:		/* Magenta */ color = FOREGROUND_RED | FOREGROUND_BLUE; break;
	case 6:		/* Yellow */ color = FOREGROUND_RED | FOREGROUND_GREEN; break;
	default:	/* White */ color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN; break;

	}

	if (!intensity == false){
		color += FOREGROUND_INTENSITY;
	}

	SetConsoleTextAttribute(h_console, color);
}

void ChangeBacktextColor(int num, BOOL intensity){
	switch (num){

	case 1:		/* Green */ color = BACKGROUND_GREEN; break;
	case 2:		/* Red   */ color = BACKGROUND_RED; break;
	case 3:		/* Blue  */ color = BACKGROUND_BLUE; break;
	case 4:		/* CYAN  */ color = BACKGROUND_GREEN | BACKGROUND_BLUE; break;
	case 5:		/* Magenta */ color = BACKGROUND_RED | BACKGROUND_BLUE; break;
	case 6:		/* Yellow */ color = BACKGROUND_RED | BACKGROUND_GREEN; break;
	default:	/* White */ color = BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_GREEN; break;

	}

	if (!intensity == false){
		color += FOREGROUND_INTENSITY;
	}

	SetConsoleTextAttribute(h_console, color);
}

void ChangeBackgroundColor(int num){

	const char *color = " ";

	switch (num){

	case 1:		/* Blue  */ color = "color 10"; break;
	case 2:		/* Green */ color = "color 20"; break;
	case 3:		/* Aqua  */ color = "color 30"; break;
	case 4:		/* Red */ color = "color 40"; break;
	case 5:		/* Magenta */ color = "color 50"; break;
	case 6:		/* Yellow */ color = "color 60"; break;
	case 7:	   /* White */ color = "color 70"; break;
	case 8:	   /* White */ color = "color 80"; break;
	case 9:	   /* White */ color = "color 90"; break;
	case 10:	   /* White */ color = "color a0"; break;
	case 11:	   /* White */ color = "color b0"; break;
	case 12:	   /* White */ color = "color c0"; break;
	case 13:	   /* White */ color = "color d0"; break;
	case 14:	   /* White */ color = "color e0"; break;
	case 15:	   /* White */ color = "color f0"; break;
	}

	system(color);


}


int gotoxyz(string user_defined_text, int y){
	int counter = 0;
	for (int i = 0; i < user_defined_text[i]; i++){
		counter += 1;
	}
	coord.X = 38 - (counter / 2);
	coord.Y = y;
	SetConsoleCursorPosition(h_console, coord);
	cout << user_defined_text;
	loadscreenx = coord.X;
	return y;
}

void MaximizeWindow()
{
	GetConsoleScreenBufferInfo(h_console, &info);
	SMALL_RECT rc;
	rc.Left = rc.Top = 0;
	rc.Right = (short)(min(info.dwMaximumWindowSize.X, info.dwSize.X) - 1);
	rc.Bottom = (short)(min(info.dwMaximumWindowSize.Y, info.dwSize.Y) - 1);
	SetConsoleWindowInfo(h_console, true, &rc);
}

void center(string user_defined_text){
	int counter = 0;
	for (int i = 0; i < user_defined_text[i]; i++){
		counter += 1;
	}
	coord.X = 38 - (counter / 2);
	SetConsoleCursorPosition(h_console, coord);
	cout << user_defined_text;
}

int gotoxyza(string user_defined_text, int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h_console, coord);
	cout << user_defined_text;
	
	return y;
}

void gotoxy(int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h_console, coord);

}

void drawrect(char rect_composition, int x, int y, int composition, int height){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h_console, coord);
	for (int i = x; i < composition; i++){
		cout << rect_composition;
	}
	for (int i = y + 1; i < height; i++){
		gotoxy(x, i);
		for (int i = x; i < composition; i++){
			if (i <= 1){
				cout << rect_composition;
			}
			else if (i >= composition - 1){
				cout << rect_composition;
			}
			else{
				cout << " ";
			}

		}
	}
	coord.X = x;
	coord.Y = height;
	SetConsoleCursorPosition(h_console, coord);
	for (int i = x; i < composition; i++){
		cout << rect_composition;
	}
}

int gotoxyzx(string user_defined_text, int y, int line_breaker){
	int breaker = 0;
	string str(user_defined_text);
	int counter = 0;
	for (int i = 0; i < user_defined_text[i]; i++){
		counter += 1;
	}

	coord.X = 8;
	coord.Y = y;
	SetConsoleCursorPosition(h_console, coord);
	for (int i = 0; i < str.length(); i++){
		if (breaker == line_breaker){
			gotoxy(coord.X, y += 1);
			breaker = 0;

		}
		else if (user_defined_text[i] == '*'){
			gotoxy(coord.X, y += 2);
			user_defined_text[i] = ' ';
			breaker = 0;
		}
		else if (user_defined_text[i] == '~'){
			gotoxy(coord.X, y += 2);
			user_defined_text[i] = ' ';
			breaker = 0;
		}
		cout << user_defined_text[i];
		breaker += 1;
	}

	return y;
}

int gotoxyzx_d(string user_defined_text, int y, int line_breaker){
	int breaker = 0;
	string str(user_defined_text);
	int counter = 0;
	for (int i = 0; i < user_defined_text[i]; i++){
		counter += 1;
	}

	coord.X = 8;
	coord.Y = y;
	SetConsoleCursorPosition(h_console, coord);
	for (int i = 0; i < str.length(); i++){
		if (breaker == line_breaker){
			gotoxy(coord.X, y += 1);
			breaker = 0;

		}
		else if (user_defined_text[i] == '~'){
			gotoxy(coord.X, y += 2);
			user_defined_text[i] = ' ';
			breaker = 0;
		}
		cout << user_defined_text[i];
		breaker += 1;
	}

	return y;
}

#endif

// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#ifndef CONSOLE_H
#define CONSOLE_H

//#include"winnt.h"

// COLOR CODES

#define BLACK 0

#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define DARKGRAY 7
#define LIGHTBLUE 8
#define LIGHTGREEN 9
#define LIGHTCYAN 10
#define LIGHTRED 11
#define LIGHTMAGENTA 12
#define YELLOW 13

#define LIGHTGRAY 14
#define WHITE 15

struct Coord
{
	int X;
	int Y;
};

//--------------------------------------------------------------------------------
// Move cursor to column 'x', line 'y'
void gotoxy(int x, int y);

//--------------------------------------------------------------------------------
// Set text color & background
void setcolor(unsigned int color=15, unsigned int background_color=0);

//--------------------------------------------------------------------------------
// Clear screen
void clrscr(void);
//--------------------------------------------------------------------------------
//references of the functions in console .cpp
// Set different font size in console
void setFontSize(int FontSize);
//--------------------------------------------------------------------------------
//Determine the present coordinates of the cursor

int wherex();
int wherey();


void fullscr();
#endif
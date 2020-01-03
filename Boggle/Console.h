// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#ifndef CONSOLE_H
#define CONSOLE_H


// COLOR CODES

#define BLACK 0

#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14

#define WHITE 15


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
//references of the following functions in console .cpp
// Set different font size in console
void setFontSize(int FontSize);
//--------------------------------------------------------------------------------
//Determine the present coordinates of the cursor
int wherex();
int wherey();
#endif
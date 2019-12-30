// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include<windows.h> // for controlling foreground & background console colors
#include"Console.h"
using namespace std;

//================================================================================

// Move cursor to column 'x', line 'y'
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//--------------------------------------------------------------------------------

// Set text color & background
void setcolor(unsigned int color, unsigned int background_color)
{
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  if (background_color == BLACK)
    SetConsoleTextAttribute(hCon, color);
  else
    //SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}

//--------------------------------------------------------------------------------

// Clear screen
void clrscr(void)
{
  COORD upperLeftCorner = { 0, 0 };
  DWORD charsWritten;
  DWORD conSize;
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO  csbi;

  GetConsoleScreenBufferInfo(hCon, &csbi);
  conSize = csbi.dwSize.X * csbi.dwSize.Y;

  // Fill with spaces
  FillConsoleOutputCharacter(hCon, TEXT(' '), conSize, upperLeftCorner, &charsWritten);
  GetConsoleScreenBufferInfo(hCon, &csbi);
  FillConsoleOutputAttribute(hCon, csbi.wAttributes, conSize, upperLeftCorner, &charsWritten);

  // Move Cursor to upper left corner
  SetConsoleCursorPosition(hCon, upperLeftCorner);
}

//--------------------------------------------------------------------------------

//referencia de extração do codigo para mudar o tamanho de letra
//h ttp://www.cplusplus.com/forum/general/118967/

void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

//--------------------------------------------------------------------------------
//referencia de extração do codigo para descobrir a posição do cursor na board
//h ttp://www.cplusplus.com/forum/general/74380/
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
		return -1;

	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
		return -1;

	return csbi.dwCursorPosition.Y;
}
//--------------------------------------------------------------------------------
//Colocar a consola em modo fullscreen
//h ttps://stackoverflow.com/questions/4053554/running-a-c-console-program-in-full-screen
void fullscr()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
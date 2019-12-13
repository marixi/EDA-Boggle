#include <windows.h> // for controlling foreground & background console colors
#include "Console.h"

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

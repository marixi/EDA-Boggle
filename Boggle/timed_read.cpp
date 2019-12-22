// Program that reads single words, during a specified time
// (using _kbhit() and _getch()
// and stores them into a text file.
// JAS - 2019/11/25
// If _kbhit() returns nonzero, a keystroke is waiting in the buffer. 
// The program can call _getch() or _getche() to get the keystroke.

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;
//==========================================================================================
// Reads a word to string 'str'
// It must be read before 'duration' time is elapsed, 
// otherwise 'str' will be an empty string
//------------------------------------------------------------------------------------------
void readStrTimed(string &str, time_t duration)
{
  const char CARRIAGE_RETURN = 13, SPACE = ' ', TAB = '\t', BACKSPACE = 8, BEEP = 7;
  str = "";
  time_t t1 = time(NULL), t2;
  int tAvail;
  t2 = time(NULL);
  tAvail = (int)(duration - (t2 - t1));

  while (tAvail > 0)
  {
    if (_kbhit())
    {
      char c;
      c = _getch();
      c = toupper(c);
      if (c == SPACE || c == TAB || c == CARRIAGE_RETURN)
      {
        cout << endl;
        return;
      }
      if (c == BACKSPACE)
        cout << BEEP;
      else
      {
        cout << c << flush;
        str = str + c;
      }
    }
    t2 = time(NULL);
    tAvail = (int)(duration - (t2 - t1));
  }
  return;
}
/*Reads several words and stores them into file named 'fileName'
all letters are converted to upercase.
The words must be read before 'duration' time is elapsed*/
void readWords(const string & fileName, time_t duration)
{
  const char BEEP = (char)7;
  time_t t1 = time(NULL), t2;
  int tAvail;

  ofstream f(fileName);

  t2 = time(NULL);
  tAvail = (int)(duration - (t2 - t1));
  cout << "Word (available time = " << tAvail << ") ? ";

  while (tAvail > 0)
  {
    string str;
    readStrTimed(str, tAvail);

    if (str != "")
      f << str << endl << flush;
    t2 = time(NULL);
    tAvail = (int)(duration - (t2 - t1));
    if (tAvail > 0)
      cout << "Word (available time = " << setw(2) << setfill('0') << tAvail << ") ? ";
    else
      cout << endl << "Time is over !" << BEEP << endl;;
  }
  f.close();
}
//==========================================================================================
int main(void)
{
  const time_t DURATION_SECONDS = 20; // you have 20 seconds to write your words
  const string FILENAME = "WORDS.TXT";
  readWords(FILENAME, DURATION_SECONDS);
  getchar();
}

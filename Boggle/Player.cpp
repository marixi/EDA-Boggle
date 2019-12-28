// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Player.h"

Player::Player()
{
	_name = "NO NAME";
	_age = 0;
	_points = 0;
}
//--------------------------------------------------------------------------------------------------------------
Player::Player(string name)
{
	_name = name;
	_age = 0;
	_points = 0;
}
//--------------------------------------------------------------------------------------------------------------
Player::Player(string name, int age)
{
	_name = name;
	_age = age;
	_points = 0;
}
//--------------------------------------------------------------------------------------------------------------
void Player::readInfo()
{
	string age;
	cout << "Insert Player's name: "; cin >> _name; // getline(cin, _name);
	cout << "Insert Player's age: "; cin >> age;
	//cin.clear();
	//cin.ignore(1000, '\n');
}
//--------------------------------------------------------------------------------------------------------------
/*
Reads a word to string 'str'
It must be read before 'duration' time is elapsed, 
otherwise 'str' will be an empty string
*/
void Player::readStrTimed(string& str, time_t duration)
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
//--------------------------------------------------------------------------------------------------------------
/*
Author: JAS
Reads several words and stores them into file named 'fileName'
all letters are converted to upercase.
The words must be read before 'duration' time is elapsed
*/
void Player::readWordsTimed(const string& fileName, time_t duration)
{
  const char BEEP = (char)7; // Isto realmente faz um beep quando é mostrado na consola.
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
//--------------------------------------------------------------------------------------------------------------
void Player::displayInfo(ostream& os) const
{
  os << "Player's Name: " << _name << endl;
  os << "Player's Age: " << _age << endl;
}
//--------------------------------------------------------------------------------------------------------------
string Player::getName()
{
	return _name;
}
//--------------------------------------------------------------------------------------------------------------
unsigned int Player::getPoints()
{
	return _points;
}
//--------------------------------------------------------------------------------------------------------------
void Player::updatePoints(unsigned int roundPoints)
{
	_points += roundPoints;
}
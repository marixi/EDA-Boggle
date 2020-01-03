// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Player.h"

Player::Player()
{
	_name = "NO NAME";
	_age = "0";
	_points = 0;
}
//--------------------------------------------------------------------------------------------------------------
Player::Player(string name)
{
	_name = name;
	_age = "0";
	_points = 0;
}
//--------------------------------------------------------------------------------------------------------------
Player::Player(string name, string age)
{
	_name = name;
	_age = age;
	_points = 0;
}
//--------------------------------------------------------------------------------------------------------------
void Player::readInfo()
{
	cout << "Insert Player's name: "; getline(cin, _name);
	cout << "Insert Player's age: "; getline(cin,_age);
}
//--------------------------------------------------------------------------------------------------------------
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
			//It allows to erase a written word, only beeping when there's an empty string
			if (c == BACKSPACE)
			{
				if (str == "")
					cout << BEEP;
				else
				{
					cout << "\b" << " \b" << flush;
					str.pop_back();
				}
			}
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
void Player::readWordsTimed(const string& fileName, time_t duration)
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

	// Closes the file stream.
	f.close();
}
//--------------------------------------------------------------------------------------------------------------
void Player::displayInfo(ostream& os) const
{
	os << "Name: " << _name << "; ";
	os << "Age: " << _age << "." << endl;
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
//--------------------------------------------------------------------------------------------------------------
void Player::setPoints(unsigned int newPoints)
{
	_points = newPoints;
}
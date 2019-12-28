// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Game.h"
#include<windows.h>
using namespace std;

Game::Game()
{
	_config = Config();
	_dictionary = Dictionary();
	_winner = "NO NAME";
}
//--------------------------------------------------------------------------------------------------------------
void Game::readPlayers()
{
	int i = 0;
	do
	{
		cout << "Player " << i + 1 << ": " << endl;
		Player p;
		p.readInfo();
		_players.push_back(p);
		_playersWords.insert(pair<string, string>(p.getName(), "NO FILE"));
		_playersPoints.insert(pair<string, int>(p.getName(), 0));
		i++;
	} while (!cin.eof());
	clrscr();
}
//--------------------------------------------------------------------------------------------------------------
void Game::readConfig(const string& filename)
{
	_config = Config(filename);
}
//--------------------------------------------------------------------------------------------------------------
void Game::readDictionary(const string& filename)
{
	_dictionary = Dictionary(filename);
}
//--------------------------------------------------------------------------------------------------------------
void Game::readBoard(const string& filename)
{
	_board = Board(filename);
}
//--------------------------------------------------------------------------------------------------------------
void Game::readPlayersWords()
{
	map<string, string>::const_iterator ms;
	pair<string, string> p;
	int duration = _config.getMaxTime();
	string filename;
	size_t i = 0;
	_board.shuffle();
	for (ms = _playersWords.begin(); ms != _playersWords.end(); ms++)
	{
		_board.display(cout);
		cout << endl << "Player " << i+1 << ": " << endl;
		p = *ms;
		filename = p.first + ".txt";
		p.second = filename;
		_players[i].readWordsTimed(filename, duration);
		clrscr();
		i++;
		Sleep(6000);
	}
}
//--------------------------------------------------------------------------------------------------------------
Config Game::getConfig()
{
	return _config;
}
//--------------------------------------------------------------------------------------------------------------
Dictionary Game::getDictionary()
{
	return _dictionary;
}
//--------------------------------------------------------------------------------------------------------------
Board Game::getBoard()
{
	return _board;
}
//--------------------------------------------------------------------------------------------------------------
bool Game::minLetters(const string word)
{
	if ((unsigned int)(sizeof(word) / sizeof(char)) < _config.getMinLetters())
		return false;
	else
		return true;
}
//--------------------------------------------------------------------------------------------------------------
bool Game::findInBoard(const string word, ostream& os)
{
	return _board.findWord(word, os);
}
//--------------------------------------------------------------------------------------------------------------
bool Game::findInDictionary(const string word)
{
	return _dictionary.find(word);
}
//--------------------------------------------------------------------------------------------------------------
bool Game::repeatedWord(const string wordSearch)
{
	int sum = 0;
	map<string, string>::const_iterator ms;
	pair<string, string> p;
	for (ms = _playersWords.begin(); ms != _playersWords.end(); ms++)
	{
		p = *ms;
		ifstream file(p.second);
		string word;
		while (!(file.eof()))
		{
			getline(file, word);
			if (word == wordSearch)
			{
				sum++;
				break;
			}
		}
	}
	if (sum > 1)
		return true;
	else
		return false;
}
//--------------------------------------------------------------------------------------------------------------
int Game::charsToPoints(const string word)
{
	int length = sizeof(word) / sizeof(char);
	switch (length)
	{
	case 3: case 4: return 1; break;
	case 5: return 2; break;
	case 6: return 3; break;
	case 7: return 5; break;
	default: return 11;
	}
}
//--------------------------------------------------------------------------------------------------------------
void Game::roundPoints(ostream& os)
{
	map<string, string>::const_iterator ms;
	map<string, int>::const_iterator mi;
	pair<string, string> ps;
	pair<string, int> pi;
	for (mi = _playersPoints.begin(); mi != _playersPoints.end(); mi++)
	{
		pi = *mi;
		for (ms = _playersWords.begin(); ms != _playersWords.end(); ms++)
		{
			ps = *ms;
			ifstream Words(ps.second);
			string word;
			while (!Words.eof())
			{
				getline(Words, word);
				if (minLetters(word) == false)
					os << word << ": 0 (the word doesn't have the minimum amount of letters necessary)." << endl;
				else if (findInBoard(word) == false)
					os << word << ": 0 (the word can't possibly be formed with this board)." << endl;
				else if (findInDictionary(word) == false)
					os << word << ": 0 (the word isn't on the list of valid words)" << endl;
				else if (repeatedWord(word) == true)
					os << word << ": 0 (the word has also been chosen by another player)" << endl;
				else
				{
					os << word << ": " << charsToPoints(word) << endl; // FALTA MOSTRAR O PATH AQUI
					pi.second += charsToPoints(word);
				}
			}
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
bool Game::checkForVictory()
{
	map<string, int>::const_iterator m;
	pair<string, int> p;
	for (m = _playersPoints.begin(); m != _playersPoints.end(); m++)
	{
		p = *m;
		if ((unsigned int)p.second >= _config.getVictoryPoints())
		{
			return true;
			_winner = p.first;
		}
	}
	return false;
}
//--------------------------------------------------------------------------------------------------------------
void Game::displayWinner(ostream& os)
{
	os << "The winner is " << _winner << "!";
}


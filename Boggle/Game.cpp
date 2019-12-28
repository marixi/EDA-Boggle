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
	_winner = Player();
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
		i++;
	} while (!cin.eof());
	_players.resize(_players.size()-1);
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
	int duration = _config.getMaxTime();
	string filename;
	_board.shuffle();
	for (size_t i = 0; i < _players.size(); i++)
	{
		_board.display(cout);
		cout << endl << "Player " << i + 1 << ": " << endl;
		filename = (_players[i]).getName() + ".txt";
		_players[i].readWordsTimed(filename, duration);
		clrscr();
		Sleep(6000);
	}
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
	for (size_t i = 0; i < _players.size(); i++)
	{
		string filename = (_players[i]).getName() + ".txt";
		ifstream file(filename);
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
	for (size_t i = 0; i < _players.size(); i++)
	{
		os << "Player " << i + 1 << ": " << endl;
		string filename = (_players[i]).getName() + ".txt";
		ifstream Words(filename);
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
				(_players[i]).updatePoints(charsToPoints(word));
			}
		}
		os << endl;
	}
	Sleep(3000);
	clrscr();
}
//--------------------------------------------------------------------------------------------------------------
bool Game::checkForVictory()
{
	bool victory = false;
	for (size_t i = 0; i < _players.size(); i++)
	{
		if ((_players[i]).getPoints() >= _config.getVictoryPoints())
		{
			victory = true;
			_winner = _players[i];
			break;
		}
	}
	return victory;
}
//--------------------------------------------------------------------------------------------------------------
void Game::displayWinner(ostream& os)
{
	os << "The winner is " << _winner.getName() << "!";
}


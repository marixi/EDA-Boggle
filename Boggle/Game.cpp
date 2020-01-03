// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Game.h"
#include<stdlib.h>
using namespace std;

Game::Game()
{
	_config = Config();
	_dictionary = Dictionary();
	_winner = Player();
}
//--------------------------------------------------------------------------------------------------------------
void Game::setGame(const string& filenameConfig)
{
	_config = Config(filenameConfig);
	_dictionary = Dictionary(_config.getFilenameDictionary());
	_board = Board(_config.getFilenameBoard());
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
	_players.resize(_players.size() - 1);
	cout << endl;
	system("pause");
	clrscr();
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
		cout << endl;
		system("pause");
		clrscr();
	}
}
//--------------------------------------------------------------------------------------------------------------
bool Game::minLetters(const string word)
{
	if ((unsigned int)(word.length() / sizeof(char)) < _config.getMinLetters())
		return false;
	else
		return true;
}
//--------------------------------------------------------------------------------------------------------------
bool Game::findInBoard(const string word, vector<Position>& wordPath)
{
	return _board.findWord(word, wordPath);
}
//--------------------------------------------------------------------------------------------------------------
bool Game::findInDictionary(string word)
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
bool Game::sameWord(const string wordSearch, vector<string> v)
{
	bool sameWord = false;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == wordSearch)
		{
			sameWord = true;
			break;
		}
	}
	return sameWord;
}
//--------------------------------------------------------------------------------------------------------------
int Game::charsToPoints(const string word)
{
	unsigned int length = word.length() / sizeof(char);
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
		// Opens game report file in append mode.
		ofstream outFile;
		outFile.open(_reportFilename, std::ios_base::app);

		outFile << endl;
		outFile << "BOARD:" << endl;
		_board.display(outFile);
		outFile << "Player " << i + 1 << " bets: " << endl;

		_board.display(os);
		os << endl << endl << "Player " << i + 1 << " bets: " << endl;

		string filename = (_players[i]).getName() + ".txt";
		ifstream Words(filename);
		string word;
		vector<string> v;
		while (!Words.eof())
		{
			getline(Words, word);
			if (!word.empty())
			{
				vector<Position> wordPath;
				if (minLetters(word) == false)
				{
					os << word << ": 0 (the word doesn't have the minimum amount of letters necessary)" << endl << endl;
					outFile << word << ": 0 (the word doesn't have the minimum amount of letters necessary)" << endl << endl;
				}
				else if (findInBoard(word, wordPath) == false)
				{
					os << word << ": 0 (the word can't possibly be formed with this board)" << endl << endl;
					outFile << word << ": 0 (the word can't possibly be formed with this board)" << endl << endl;
				}
				else if (findInDictionary(word) == false)
				{
					os << word << ": 0 (the word isn't on the list of valid words)" << endl << endl;
					outFile << word << ": 0 (the word isn't on the list of valid words)" << endl << endl;
				}
				else if (repeatedWord(word) == true)
				{
					os << word << ": 0 (the word has also been chosen by another player)" << endl << endl;
					outFile << word << ": 0 (the word has also been chosen by another player)" << endl << endl;
				}
				else if (sameWord(word, v)==true)
				{
					os << word << ": 0 (the word has already been called)" << endl << endl;
					outFile << word << ": 0 (the word has already been called)" << endl << endl;
				}
				else
				{
					v.push_back(word);
					showWordPathinFile(word, wordPath, outFile);
					outFile << word << ": " << charsToPoints(word) << " points" << endl << endl;

					showWordPathinConsole(word, wordPath, os);
					os << word << ": " << charsToPoints(word) << " points" << endl << endl;

					(_players[i]).updatePoints(charsToPoints(word));
					Sleep(1000);
					int r = wherex(); int t = wherey();
					gotoxy(0, 0);
					_board.display(os);
					gotoxy(r, t);
				}
			}
		}
		outFile << "Total Points: " << _players[i].getPoints() << endl;
		outFile << endl;

		os << endl;
		os << "Total Points: " << _players[i].getPoints() << endl;
		Words.close();

		os << endl;
		system("pause");
		clrscr();
	}
}
//--------------------------------------------------------------------------------------------------------------
void Game::showWordPathinConsole(const string& word, vector<Position>& wordPath, ostream& os)
{
	int colorCode=0;
	do
	{
		int color = rand() % 14 + 1;
		colorCode = color;
	} while (colorCode == 7 || colorCode == 8 || colorCode == 9);

	setcolor(colorCode);
	os << word;
	setcolor();
	os << " can be found in the board, following the path : \n";

	for (size_t a = 0; a < word.length(); a++)
	{
		os << "(" << wordPath[a].lin << "," << wordPath[a].col << ")   ";

		int x = wherex(); int y = wherey(); int c = 0;

		switch (wordPath[a].col)
		{
		case 1: c = 3; break;
		case 2: c = 6; break;
		case 3: c = 9; break;
		case 4: c = 12; break;
		case 5: c = 15; break;
		case 6: c = 18; break;
		}
		gotoxy(c, wordPath[a].lin);
		setcolor(colorCode);
		cout << "\b" << word[a];
		setcolor();
		gotoxy(x, y);
		Sleep(500);
	}
	os << endl << endl;
}
//--------------------------------------------------------------------------------------------------------------
void Game::showWordPathinFile(const string& word, vector<Position>& wordPath, ostream& os)
{
	os << word << " can be found in the board, following the path : \n";

	for (size_t a = 0; a < word.length(); a++)
	{
		os << "(" << wordPath[a].lin << "," << wordPath[a].col << ")   ";

	}
	os << endl << endl;
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
	os << "The winner is " << _winner.getName() << "!" << endl << endl;
}
//--------------------------------------------------------------------------------------------------------------
void Game::gameReport(const unsigned int mode)
{
	switch (mode)
	{
	case 1: // Writes tittle and players into game report.
	{
		ofstream f(_reportFilename);
		f << "Boggle Game Report " << _gameNumber << endl << endl;

		f << "PLAYERS:" << endl;
		int i = 1;
		for (auto player : _players)
		{
			f << "Player " << i << " - ";
			player.displayInfo(f);
			i++;
		}
		f.close();
		break;
	}
	case 2: // Writes winner into game report.
	{
		ofstream f;
		f.open(_reportFilename, std::ios_base::app);
		displayWinner(f);
		f.close();
		break;
	}
	default:
		break;
	}
}
//--------------------------------------------------------------------------------------------------------------
void Game::discoverReportFilename()
{
	ifstream fi("BOGGLE_GAME_NUM.TXT");
	if (fi.fail())
	{
		cerr << "Error: \"" << "BOGGLE_GAME_NUM.TXT" << "\" was not found! \n";
		exit(1);
	}

	fi >> _gameNumber;
	fi.close();

	ofstream fo("BOGGLE_GAME_NUM.TXT");
	fo << _gameNumber + 1;
	fo.close();

	_gameNumber++;
	_reportFilename = "BOGGLE_GAME_" + to_string(_gameNumber) + ".TXT";
}
//--------------------------------------------------------------------------------------------------------------
void Game::clearPoints()
{
	for (size_t i = 0; i < _players.size(); i++)
		(_players[i]).setPoints(0);
}
//--------------------------------------------------------------------------------------------------------------
void Game::clearPlayers()
{
	_players.clear();
}

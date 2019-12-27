// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Game.h"
using namespace std;

Game::Game()
{
	_players.push_back(Player());
	_config = Config();
	_dictionary = Dictionary();
	_playersWords.insert(pair <Player, string>("NO PLAYER", "NO FILE"));
	_playersPoints.insert(pair <Player, int>("NO PLAYER", 0));
}
//--------------------------------------------------------------------------------------------------------------
void Game::readPlayers()
{
	int i = 0;
	do
	{
		cout << "Player " << i + 1 << ": ";
		Player p;
		p.readInfo();
		_players.push_back(p);
		_playersWords.insert(pair<Player, string>(p, "NO FILE"));
		_playersPoints.insert(pair<Player, int>(p, 0));
	} while (!cin.eof());
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
void Game::readPlayersWords()
{
	map<Player, string>::const_iterator mi;
	pair<Player, string> p;
	int duration = _config.getMaxTime();
	string filename;
	size_t i = 0;
	for (mi = _playersWords.begin(); mi != _playersWords.end(); mi++)
	{
		filename = _players[i].getName() + ".txt";
		p = *mi;
		(p.first).readWordsTimed(filename, duration);
		i++;
	}
}
//--------------------------------------------------------------------------------------------------------------
bool Game::minLetters(const string word)
{
	if (sizeof(word) / sizeof(char) < _config.getMinLetters())
		return false;
}
//--------------------------------------------------------------------------------------------------------------
bool possibleForm(const string word)
{
	// Return false se nao possivel formar
}
//--------------------------------------------------------------------------------------------------------------
bool Game::findWord(const string word)
{
	return _dictionary.find(word);
}
//--------------------------------------------------------------------------------------------------------------
bool Game::repeatedWord(const string word)
{
	// Return true se repetida
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
	case 8:return 11; break;
	default: return 11;
	}
}
//--------------------------------------------------------------------------------------------------------------
bool Game::checkForVictory(pair<Player, int> p)
{
	if (p.second >= _config.getVictoryPoints())
		return true;
}
//--------------------------------------------------------------------------------------------------------------
void Game::roundPoints(ostream& os)
{
	map<Player, string>::const_iterator ms;
	map<Player, int>::const_iterator mi;
	pair<Player, string> ps;
	pair<Player, int> pi;
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
				else if (possibleForm(word) == false)
					os << word << ": 0 (the word can't possibly be formed with this board)." << endl;
				else if (findWord(word) == false)
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
		os << (pi.first).getName() << "'s points: " << pi.second;
		if (checkForVictory(pi) == true)
			os << (pi.first).getName() << " is the winner!"; // E DE ALGUMA MANEIRA FECHAR TUDO
	}
}



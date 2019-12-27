// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include"Player.h"
#include"Config.h"
#include"Dictionary.h"
#include<vector>
#include<sstream>
using namespace std;

class Game
{
public:
	Game();
	void readPlayers();
	void readConfig(const string& filename);
	void readDictionary(const string& filename);
	void readPlayersWords();
	void roundPoints(ostream& os);
private:
	vector<Player> _players;
	Config _config;
	Dictionary _dictionary;
	map<Player, string> _playersWords;
	map<Player, int> _playersPoints;
	bool minLetters(const string word);
	bool possibleForm(const string word);
	bool findWord(const string word);
	bool repeatedWord(const string word);
	int charsToPoints(const string word);
	bool checkForVictory(pair<Player, int> p);
};

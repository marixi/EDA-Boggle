// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include"Player.h"
#include"Config.h"
#include"Dictionary.h"
#include"Board.h"
#include"Console.h"
#include<vector>
#include<sstream>
#include<windows.h>
using namespace std;

class Game
{
public:
	Game();
	void setGame(const string& filenameConfig); // Reads configuration, board and dictionary
	void readPlayers(); // Reads players' info
	void readPlayersWords(); // Shows the board and reads the words from consecutive players
	void roundPoints(ostream& os); // Reads words and calculates points
	bool checkForVictory(); // Checks if the players have reacher the necessary points to win
	void displayWinner(ostream& os); // Shows the winner on the screen
private:
	// Attributes 
	vector<Player> _players;
	Config _config;
	Dictionary _dictionary;
	Board _board;
	Player _winner;
	bool minLetters(const string word);
	bool findInBoard(const string word, vector<Position>& wordPath);
	void showWordPath(const string& word,vector<Position>& wordPath, ostream& os = cout);
	bool findInDictionary(const string word);
	bool repeatedWord(const string wordSearch);
	int charsToPoints(const string word);
	
};

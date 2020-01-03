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
	Game(); // Reads default configuration, board and dictionary.
	void setGame(const string& filenameConfig); // Reads configuration, board and dictionary.
	void readPlayers(); // Reads players' info.
	void readPlayersWords(); // Shows the board and reads the words from consecutive players.
	void roundPoints(ostream& os); // Reads words and calculates points.
	bool checkForVictory(); // Checks if the players have reached the necessary points to win.
	void displayWinner(ostream& os); // Shows the winner.
	void gameReport(const unsigned int mode); // Creates a Game Report with the information from that game.
	void discoverReportFilename(); // Reads and returns from a file the number of the game, and then increments that number.
	void clearPoints(); //Sets all the players point to zero
	void clearPlayers(); // deletes the players by erasing their data
private: 
	vector<Player> _players; //vector of players to keep their data
	Config _config; //configuration of the game data
	Dictionary _dictionary; //filename of the list of valid words
	string _reportFilename; //filename to write the report
	unsigned int _gameNumber; //number of played games
	Board _board; //board with initialized cubes
	Player _winner; //player that reached the victory faster
	bool minLetters(const string word); // Checks if the word has minumum letters.
	bool sameWord(const string wordSearch, vector<string> v); // Checks if a player as introduced the same word twice.
	bool findInBoard(const string word, vector<Position>& wordPath); // Checks if the word can be found on the board.
	void showWordPathinConsole(const string& word,vector<Position>& wordPath, ostream& os = cout); // Shows the path of the found word by coloring the board and indicating the index of each letter.
	void showWordPathinFile(const string& word, vector<Position>& wordPath, ostream& os);// Shows the path of the found word in the file.
	bool findInDictionary(const string word); // Checks if the word can be found on the dictionary.
	bool repeatedWord(const string wordSearch); // Checks if more than one player has chosen that word.
	int charsToPoints(const string word); // Converts valid word into points.
};

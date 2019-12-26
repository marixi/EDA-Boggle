#pragma once
#include "Board.h"
#include "Player.h"

class Game
{
private:
	string _filenameDictionary; 
	string _filenameBoard;
	vector<Player> _players;
	unsigned int _maxTime; // Maximum time for each round/game.
	unsigned int _minLetters; // Minimum of letters of a word.
	unsigned int _victoryPoints; // Points required to win.
public:
	Game();
	Game(const string& filename);
	void readGameConfig(const string& filename); //Almost the same has the constructor but it changes an existing object.
	void readPlayers(istream& is);
	//void wordsToPoints; // Case Structure that translates the number of words that the player tried to guess into words.
	//Not sure if the above function makes sense in this class yet.

};


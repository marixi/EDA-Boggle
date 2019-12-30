// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Config
{
public:
	Config(); // Creates default configuration.
	Config(const string& filename); // Reads configuration from 'filename'.
	void displayConfig(ostream& os) const; // Displays configuration.
	string getFilenameDictionary() const; // Returns filename for loading dictionary.
	string getFilenameBoard() const; // Returns filename for loading board.
	unsigned int getMaxTime() const; // Returns maximum time.
	unsigned int getMinLetters() const; // Returns minimum letters.
	unsigned int getVictoryPoints() const; // Returns victory points.

private:
	string _filenameDictionary;
	string _filenameBoard;
	unsigned int _maxTime; // Maximum time for each round/game.
	unsigned int _minLetters; // Minimum of letters of a word.
	unsigned int _victoryPoints; // Points required to win.
	void defineAttributes(string aux, string& attributes);
};


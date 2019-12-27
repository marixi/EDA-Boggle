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
	Config();
	Config(const string& filename);
	void displayConfig(ostream& os) const;
	unsigned int getMaxTime() const;
	unsigned int getMinLetters() const;
	unsigned int getVictoryPoints() const;
private:
	string _filenameDictionary;
	string _filenameBoard;
	unsigned int _maxTime; // Maximum time for each round/game.
	unsigned int _minLetters; // Minimum of letters of a word.
	unsigned int _victoryPoints; // Points required to win.
	void defineParameters(string aux, string& parameter);
};


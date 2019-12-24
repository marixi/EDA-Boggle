// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Dictionary
{
public:
	Dictionary(const string& filename); // load "dictionary" from 'filename'
	bool find(const string& word); // finds 'word' in "dictionary"
	void display(ostream& os) const; // displays all words (don't do it for long "dictionaries"...)
	// TO DO: choose other methods, if necessary
private:
	map<int, string> dictionary;
	// TO DO: choose attributes (and methods, if necessary)
};
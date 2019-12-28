// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<map>
using namespace std;

class Dictionary
{
public:
	Dictionary();
	Dictionary(const string& filename); // Loads "dictionary" from 'filename'.
	bool find(const string& word); // Finds 'word' in '_dictionary'.
	void display(ostream& os) const; // Displays all the words. (Don't do it for big dictionaries!)
private:
	map<int, string> _dictionary;
};
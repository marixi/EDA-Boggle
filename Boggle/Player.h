// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier
#pragma once

#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

class Player
{
public:
	Player(); // builds a player with name="NO NAME"
	Player(string name);
	Player(string name, int age);
	void readInfo(); // reads player's info (name, age)
	void readWordsTimed(const string& fileName, time_t duration);
	void display(ostream& os) const;  // showInfo()
private:
	string _name; // name of the player
	unsigned int _age;
	void readStrTimed(string& str, time_t duration);
	// TO DO: other attributes, namely the words of his/her bet (and methods, if necessary)
};

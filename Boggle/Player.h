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
	void readInfo(); // reads player's info (name, age)
	void readWordsTimed(unsigned int duration); // reads words of the player's bet, in one round
	void display(ostream& os) const;  // showInfo()
	// TO DO: choose other methods, if necessary
private:
	string _name; // name of the player
	unsigned int _age;
	// TO DO: other attributes, namely the words of his/her bet (and methods, if necessary)
};

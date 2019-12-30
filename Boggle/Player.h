// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include<iostream>
#include<iomanip>
#include<ostream>
#include<fstream>
#include<string>
#include<ctime>
#include<conio.h>
using namespace std;

class Player
{
public:
	Player(); // builds a player with name="NO NAME".
	Player(string name); // builds a player with a name.
	Player(string name, int age); // builds a player with a name and age.
	void readInfo(); // reads player's info (name, age).
	void readWordsTimed(const string& fileName, time_t duration); // reads words of the player's bet, in one round.
	void displayInfo(ostream& os) const;  // displays the player's name and age.
	string getName(); // access to the player's name.
	unsigned int getPoints(); // access to the player's points.
	void updatePoints(unsigned int roundPoints); // update player's points.
private:
	string _name; // name of the player.
	unsigned int _age; // age of the player.
	void readStrTimed(string& str, time_t duration);
	unsigned int _points; // total points of the player in the game.
};

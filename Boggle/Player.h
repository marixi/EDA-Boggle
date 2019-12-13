// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once

class Player
{
public:
	Player(); // builds a player with name="NO NAME"
	void readInfo(); // reads player's info (name, age)
	void readWordsTimed(unsigned int duration); // reads words of the player's bet, in one round
	void display(ostream& os) const;  // showInfo()
	// TO DO: choose other methods, if necessary
private:
	string _name; // name of the player
	// TO DO: other attributes, namely the words of his/her bet (and methods, if necessary)
};

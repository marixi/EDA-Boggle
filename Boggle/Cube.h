// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include<vector>
#include<iostream>
#include<istream>
#include<ostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Cube
{
public:
	Cube(); // Builds a cube with '*' on all the sides.
	Cube(const vector<char>& letters); // Builds a cube with chars in all of the sides.
	void roll(); // Randomly changes the _topSide of the Cube.
	char getTopLetter() const; // Returns the letter on top of the Cube.
	void displayTop(ostream& os) const; // Displays top letter.
	void displayAll(ostream& os) const; // Display alls letters on the Cube's sides.
private:
	vector<char> _letters; // Each char of the vector corresponds to one side of the Cube.
	size_t _topSide; // The side that is faced up. Goes from 0 to 5.
};
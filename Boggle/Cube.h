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
	Cube(); // build a cube with '*' on all faces
	Cube(const vector<char>& letters); // build a cube with 'letters' on faces
	void roll(); // roll cube => change _topSide
	char getTopLetter() const; // get top letter
	void displayTop(ostream& os) const; // display top letter
	void displayAll(ostream& os) const; // display all letters existing on the cube faces
private:
	vector<char> _letters; // the letters of the cube
	size_t _topSide; // the side up: 0..5
};
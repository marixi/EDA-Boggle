#pragma once
struct Position // POSITION.H
{
	int lin, col; // position of a cube (top letter) on the board
};

class Board
{
public:
	Board(size_t numRows = 4, size_t numCols = 4); // build a board w/cubes having '*' on faces
	Board(const string& filename); // load board from 'filename'
	char getTopLetter(const Position& pos) const; // get top letter at position 'pos'
	void shuffle(); // roll all cubes and shuffle them on the board
	void display(ostream& os) const; // display board
	bool findWord(string word, vector<Position>& path); // find 'word' on board
	// if 'word' is found, 'path' must contain the coordinates (lin,col) of the letters of the word
	// TO DO: choose other methods, if necessary
private:
	size_t _numRows, _numCols; // number of columns and number of rows of the board
	vector<vector<Cube>> _board; // board representation
	// other attributes and methods
};
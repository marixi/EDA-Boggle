// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include"Cube.h"
#include"Console.h"
#include<fstream>
#include<string>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

struct Position
{
	int lin, col; // position of a cube (top letter) on the board
};

class Board
{
public:
	Board(size_t numRows = 4, size_t numCols = 4); // Builds a board with default Cubes.
	Board(const string& filename); // Loads board from 'filename'.
	Cube cubeInPosition(const Position& pos); // Gives cube in position 'pos'.
	char getTopLetter(const Position& pos) const; // Get top letter at position 'pos'.
	void shuffle(); // Rolls all cubes and shuffles them on the board.
	void display(ostream& os) const; // Displays board.
	bool findWord(string word, vector<Position>& wordPath);
private:
	void replace(unsigned int indexrow,unsigned int indexcol, Cube c);
	void replace(const Position& pos, Cube c);
	void isNextLetter(const vector<vector<char>>& board, vector<vector<bool>>& visited, size_t row, size_t col, string& str, const string& word, bool& found, vector<Position>& path);
	bool findWordAux(const vector<vector<char>>& board, vector<vector<bool>>& visited, size_t i, size_t j, string& str, const string& word, bool& found, vector<Position>& path);

	// Class Atributes
	size_t _numRows, _numCols; // Number of columns and number of rows of the board
	vector<vector<Cube>> _board; // Vector of Cubes by rows and columns.
};
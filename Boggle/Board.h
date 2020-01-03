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
	int lin, col; // position of a cube (top letter) on the console board
};

class Board
{
public:
	Board(size_t numRows = 4, size_t numCols = 4); // Builds a board with default Cubes.
	Board(const string& filename); // Loads board from 'filename'.
	char getTopLetter(const Position& pos) const; // Get top letter at position 'pos'.
	void shuffle(); // Rolls all cubes and shuffles them on the board.
	void display(ostream& os) const; // Displays board.
	bool findWord(string word, vector<Position>& wordPath); // Returns true if a word can be found on the board.

private:
	void isNextLetter(const vector<vector<char>>& board, vector<vector<bool>>& visited, size_t row, size_t col, string& str, const string& word, bool& found, vector<Position>& path);//checks if the letter is valid and builds the correspondent path
	bool findWordAux(const vector<vector<char>>& board, vector<vector<bool>>& visited, size_t i, size_t j, string& str, const string& word, bool& found, vector<Position>& path); // returns true if an adjacent letter is avlid to build the word
	size_t _numRows, _numCols; // Number of columns and number of rows of the board
	vector<vector<Cube>> _board; // Vector of Cubes by rows and columns.
};
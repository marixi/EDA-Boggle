// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#pragma once
#include"Cube.h"
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
	Board(size_t numRows = 4, size_t numCols = 4); // build a board w/cubes having '*' on faces
	Board(const string& filename); // load board from 'filename'
	Cube cubeInPosition(const Position& pos);//Position in the game (1 to 4)
	char getTopLetter(const Position& pos) const; // get top letter at position 'pos'
	void shuffle(); // roll all cubes and shuffle them on the board
	void display(ostream& os) const; // display board
	bool findWord(string word, ostream& os); //(string word, vector<Position>& path); // find 'word' on board
private:
	void replace(unsigned int indexrow,unsigned int indexcol, Cube c); //os replaces ja nao sao precisos, mas vou deixar ate ao fim
	void replace(const Position& pos, Cube c);
	bool findWordAux(const vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& str, const string& word, bool& found, ostream& os, vector<Position>& path);

	size_t _numRows, _numCols; // number of columns and number of rows of the board
	vector<vector<Cube>> _board; // board representation
};
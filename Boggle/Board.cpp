// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Board.h"
using namespace std;

Board::Board(size_t numRows = 4, size_t numCols = 4)
{
	for (size_t i = 0; i < numRows; i++)
	{
		vector<Cube> row;
		for (size_t j = 0; j < numCols; j++)
		{
			row.push_back(Cube());
		}
		_board.push_back(row);
	}
}

//---------------------------------------------------------------------------------------------------------------
Board::Board(const string& filename)
{
	ifstream f(filename);

	if (f.fail())
		cerr << "Error: \"" << filename << "\" was not found! \n";

	string s1; int n1 = 0, int n2 = 0, char ch;

	if (!(f >> s1 >> n1 >> ch >> n2))
		cerr << "Error: Failed to read board size.";

	_numRows = n1;
	_numCols = n2;

	string header;
	getline(f, header);

	_board.resize(n1);
	for (size_t row = 0; row < n1; row++)
		_board[row].resize(n2);

	int a = 0, b = 0;

	for (size_t i = 0; i < n1 * n2; i++)
	{
		vector<char> faces;
		char face;

		for (size_t j = 0; j < 6; j++) // 6 is the number of faces of a cube.
		{
			f >> face;
			faces.push_back(face);
		}

		_board[a][b] = Cube(faces);

		if (b < n2)
			b++;
		else
		{
			b = 0;
			a++;
		}
	}

}

//---------------------------------------------------------------------------------------------------------------
char Board::getTopLetter(const Position& pos) const
{
	Cube temp = _board[pos.lin][pos.col];
	return temp.getTopLetter();
}

//---------------------------------------------------------------------------------------------------------------
void Board::shuffle()
{
	for (size_t row = 0; row < _numRows; row++)
	{
		for (size_t col = 0; col < _numCols; col++)
		{
			_board[row][col].roll();
		}
	}

	// Falta fazer shuffle mas não sei em que isso consiste ainda. 
	//Possivelmente, fazer um rand() na posição dos cubos.
}

//---------------------------------------------------------------------------------------------------------------
void Board::display(ostream& os) const
{
	for (size_t row = 0; row < _numRows; row++)
	{
		for (size_t col = 0; col < _numCols; col++)
		{
			_board[row][col].displayTop(os);
		}
	}
}

//---------------------------------------------------------------------------------------------------------------
bool Board::findWord(string word, vector<Position>& path)
{
	// Meter a função que o prof disponibilizou e perceber como funciona.
}


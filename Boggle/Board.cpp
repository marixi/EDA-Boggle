// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Board.h"
using namespace std;

Board::Board(size_t numRows, size_t numCols)
{
	_numRows = numRows;
	_numCols = numCols;
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
	// Checks if the text file exists.
	ifstream f(filename);
	if (f.fail())
	{
		cerr << "Error: \"" << filename << "\" was not found! \n";
		exit(1);
	}

	// Checks if the text file has the correct format and tries to read board size.
	string s1; size_t n1 = 0; size_t n2 = 0; char ch;
	if (!(f >> s1 >> n1 >> ch >> n2) || n1 != n2)
	{
		cerr << "Error: Failed to read board size.";
		exit(1);
	}

	_numRows = n1;
	_numCols = n2;

	_board.resize(n1, vector<Cube>(n2));

	size_t a = 0; size_t b = 0;
	for (size_t i = 0; i < n1 * n2; i++)
	{
		vector<char> faces(6);
		char face;
		for (size_t j = 0; j < 6; j++) // 6 is the number of faces of a cube
		{
			f >> face;
			faces[j] = face;
		}
		_board[a][b] = Cube(faces);
		if (b < n2 - 1) // Increment the position of the cubes
			b++;
		else
		{
			b = 0;
			a++;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
Cube Board::cubeInPosition(const Position& pos)
{
	return _board[pos.lin - 1][pos.col - 1];
}
//---------------------------------------------------------------------------------------------------------------
char Board::getTopLetter(const Position& pos) const
{
	Cube temp = _board[pos.lin - 1][pos.col - 1]; // QUERIA POR ESTA MERDA COM A FUNCAO DE CIMA | isto dá para fazer mas tem de se tirar o const
	return temp.getTopLetter();
}
//---------------------------------------------------------------------------------------------------------------
void Board::shuffle()
{
	//Rolls randomly every cube on the board.
	for (size_t row = 0; row < _numRows; row++)
	{
		for (size_t col = 0; col < _numCols; col++)
		{
			_board[row][col].roll();
		}
	}
	//Randomly shuffles the cubes on the board.
	random_shuffle(_board.begin(), _board.end());
}
//---------------------------------------------------------------------------------------------------------------
void Board::display(ostream& os) const
{
	os << "  ";
	for (size_t header = 0; header < _numRows; header++)
	{
		os << header + 1 << "  ";
	}
	os << "\n";

	for (size_t row = 0; row < _numRows; row++)
	{
		os << row + 1 << " ";
		for (size_t col = 0; col < _numCols; col++)
		{
			_board[row][col].displayTop(os);
			os << "  ";
		}
		os << "\n";
	}
	os << "\n";
}
//---------------------------------------------------------------------------------------------------------------
bool Board::findWord(string word, ostream& os)//(string word, vector<Position>& path) -> argumentos usados inicialmente pelo prof
{
	// Mark all characters as not visited 
	vector<vector<bool>> visited(_numRows, vector<bool>(_numCols, false));

	// Initialize test word 
	string str = "";

	//Put word in upper case
	for (size_t i = 0; i < word.size(); i++)
	{
		word[i] = toupper(word[i]);
	}

	//declaration of the path
	vector<Position> path;

	//initialize a board with only the top char
	vector<vector<char>>boardTop;// FAZER O MOLDE PARA ESTA boardtop PARA SER PASSADA PARA A FUNCAO SEGUINTE
	boardTop.resize(_numRows, vector<char>(_numCols));

	for (size_t a = 0; a < _numRows; a++)
		for (size_t b = 0; b < _numCols; b++)
			boardTop[a][b] = _board[a][b].getTopLetter();


	bool found = false;

	// Consider every character and look for 'word', starting with the first character
	//once that is found pass to findWordAux
	for (size_t i = 0; i < _numRows; i++)
		for (size_t j = 0; j < _numCols; j++)
			if (_board[i][j].getTopLetter() == word[0])
			{
				Position firstlett;
				firstlett.lin = i + 1;
				firstlett.col = j + 1;
				path.push_back(firstlett);

				findWordAux(boardTop, visited, i, j, str, word, found, os, path);
			}

	return found; //depois ao testar dizer que se saiu true entao ta otimo... se saiu false entao deu asneira
}
//---------------------------------------------------------------------------------------------------------------
void Board::isNextLetter(const vector<vector<char>>& board, vector<vector<bool>>& visited, size_t row, size_t col, string& str, const string& word, bool& found, ostream& os, vector<Position> path)
{
	if (row >= 0 && col >= 0 && !visited[row][col] && str.length() < word.length() && !found && word.substr(0, str.length()) == str)
	{
		Position addUpLetter;
		addUpLetter.lin = row + 1;
		addUpLetter.col = col + 1;
		path.push_back(addUpLetter);

		findWordAux(board, visited, row, col, str, word, found, os, path);
	}
}
//---------------------------------------------------------------------------------------------------------------
bool Board::findWordAux(const vector<vector<char>>& board, vector<vector<bool>>& visited, size_t i, size_t j, string& str, const string& word, bool& found, ostream& os, vector<Position>& path)
{
	// Mark current board cell as visited and append current character to 'str'

	visited[i][j] = true;
	str = str + board[i][j];

	// If 'str' is equal to 'word', then "announce" it has been found
	if (str == word)
	{
		found = true;
		os << word << " can be found in the board, following the path : \n";
		for (size_t a = 0; a < path.size(); a++)
		{
			os << "(" << path[a].lin << "," << path[a].col << ") \n";
		}

	}
	else // The word isn't complete.
	{
		// Visit 8 adjacent cells of board[i][j] 
		if (i == 0 && j == 0)
		{
			for (size_t row = i; row <= i + 1 && row < _numRows; row++)
				for (size_t col = j; col <= j + 1 && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		else if (i == 0 && (j >= 1 && j < _numCols - 1))
		{
			for (size_t row = i; row <= i + 1 && row < _numRows; row++)
				for (size_t col = j-1; col <= j + 1 && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		else if (i == 0 && j == _numCols - 1)
		{
			for (size_t row = i; row <= i + 1 && row < _numRows; row++)
				for (size_t col = j-1; col <= j && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		else if (j == 0 && (i >= 1 && i < _numRows - 1))
		{
			for (size_t row = i-1; row <= i + 1 && row < _numRows; row++)
				for (size_t col = j; col <= j + 1 && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		else if (i == _numRows - 1 && j == 0)
		{
			for (size_t row = i-1; row <= i && row < _numRows; row++)
				for (size_t col = j; col <= j + 1 && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		else if (i == _numRows - 1 && j == _numCols - 1)
		{
			for (size_t row = i-1; row <= i && row < _numRows; row++)
				for (size_t col = j-1; col <= j && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		else
		{
			for (size_t row = i - 1; row <= i + 1 && row < _numRows; row++)
				for (size_t col = j - 1; col <= j + 1 && col < _numCols; col++)
					isNextLetter(board, visited, row, col, str, word, found, os, path);
		}
		// Fazer o vetor de positions path com push_backs (found true) e pull_backs (!found)
// Erase current character from string, 
// remove character position from 'path' and
// mark visited[i][j] as false
		if (!found)
		{
			str.erase(str.length() - 1);
			visited[i][j] = false;
			path.pop_back();
		}
	}
	return found;
	//se uma das letras falha reposta not found e o findwordaux corre todo outra vez,
}
//---------------------------------------------------------------------------------------------------------------
void Board::replace(unsigned int indexrow, unsigned int indexcol, Cube c)
{
	_board[indexrow][indexcol] = c;
}
//---------------------------------------------------------------------------------------------------------------
void Board::replace(const Position& pos, Cube c)
{
	unsigned int indexrow = pos.lin - 1;
	unsigned int indexcol = pos.col - 1;
	_board[indexrow][indexcol] = c;
}
//---------------------------------------------------------------------------------------------------------------

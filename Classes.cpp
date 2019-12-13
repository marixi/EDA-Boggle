class Cube
{
public:
  Cube(); // build a cube with '*' on all faces
  Cube(const vector<char> &letters); // build a cube with 'letters' on faces
  void roll(); // roll cube => change _topSide
  char getTopLetter() const; // get top letter
  void displayTop(ostream &os) const; // display top letter
  void displayAll(ostream &os) const; // display all letters existing on the cube faces
  // TO DO: choose other methods, if necessary
private:
  vector<char> _letters; // the letters of the cube
  size_t _topSide; // the side up: 0..5
};
//==================================================================================================== 
struct Position // POSITION.H
{
  int lin, col; // position of a cube (top letter) on the board
};
//------------------------------------------------------------------------------------------
class Board
{
public:
  Board(size_t numRows = 4, size_t numCols = 4); // build a board w/cubes having '*' on faces
  Board(const string &filename); // load board from 'filename'
  char getTopLetter(const Position &pos) const; // get top letter at position 'pos'
  void shuffle(); // roll all cubes and shuffle them on the board
  void display(ostream &os) const; // display board
  bool findWord(string word, vector<Position> &path); // find 'word' on board
  // if 'word' is found, 'path' must contain the coordinates (lin,col) of the letters of the word
  // TO DO: choose other methods, if necessary
private:
  size_t _numRows, _numCols; // number of columns and number of rows of the board
  vector<vector<Cube>> _board; // board representation
  // other attributes and methods
};
//====================================================================================================
class Dictionary
{
public:
  Dictionary(const string &filename); // load "dictionary" from 'filename'
  bool find(const string &word); // finds 'word' in "dictionary"
  void display(ostream &os) const; // displays all words (don't do it for long "dictionaries"...)
  // TO DO: choose other methods, if necessary
private:
  // TO DO: choose attributes (and methods, if necessary)
};
//====================================================================================================
class Player
{
public:
  Player(); // builds a player with name="NO NAME"
  void readInfo(); // reads player's info (name, age)
  void readWordsTimed(unsigned int duration); // reads words of the player's bet, in one round
  void display(ostream &os) const;  // showInfo()
  // TO DO: choose other methods, if necessary
private:
  string _name; // name of the player
  // TO DO: other attributes, namely the words of his/her bet (and methods, if necessary)
};
//====================================================================================================


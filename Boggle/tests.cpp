// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Dictionary.h"
#include"Cube.h"
#include"Player.h"
#include"Board.h"
using namespace std;

// This file is where we tested the functions that were developed.
//The position declared in the tests is the postion in the board so from rows and columns 1 to 4

// Test for the dictionary functions
void testDictionaryConstructorAndDisplay()
{
	string filename = "WORDS_TEST.TXT";
	Dictionary dic(filename);
	dic.display(cout);
}

bool testDictionaryFind()
{
	string filename = "WORDS_TEST.TXT";
	Dictionary dic(filename);
	return dic.find("abacates");
}

// Test for the cube functions
void testCubeConstructorAndDisplayAll()
{
	vector<char> letters = { 'A','B','C','D','E','F' };
	Cube cube(letters);
	cube.displayAll(cout);
}

char testCubeGetTopLetter()
{
	vector<char> letters = { 'A','B','C','D','E','F' };
	Cube cube(letters);
	return cube.getTopLetter();
}

void testCubeRollAndDisplayTop()
{
	vector<char> letters = { 'A','B','C','D','E','F' };
	Cube cube(letters);
	cube.roll();
	cube.displayTop(cout);
}

// Test for the player functions
void testPlayerConstructorAndDisplay()
{
	string name = "Avo Cantigas";
	int age = 70;
	Player player(name, age);
	player.display(cout);
}

void testPlayerReadInfo()
{
	Player player;
	player.readInfo();
	player.display(cout);
}

void testPlayerReadWordsTimed()
{
	Player player;
	player.readWordsTimed("results readWordsTimed.txt",10);
}

// Test for the board functions
void testBoardConstructorsAndDisplay()
{
	Board b1;
	b1.display(cout);
	Board b2("BOARD_INT.txt");
	b2.display(cout);
}

void testBoardCubeInPosition()
{
	Board b("BOARD_INT.txt");
	Position pos = { 1,1 };
	Cube c = b.cubeInPosition(pos);
	c.displayAll(cout);
}

void testBoardTopLetter()
{
	Board b("BOARD_INT.txt");
	Position pos = { 1,1 };
	char topLetter = b.getTopLetter(pos);
	cout << "Top Letter: " << topLetter;
}

void testBoardShuffle()
{
	Board b("BOARD_INT.txt");
	b.display(cout);
	b.shuffle();
	b.display(cout);
}

void testBoardFindWordanddisplayPath()
{
	Board b("BOARD_INT.txt");
	b.display(cout);
	string s = "reoideentsaebge";

	bool f;
	f=b.findWord(s,cout);
	cout << endl << f << endl;
}

int main()
{
	/*cout << "Test for the dictionary functions: " << endl;
	testDictionaryConstructorAndDisplay();
	cout << testDictionaryFind() << endl;*/

	/*cout << endl << "Test for the cube functions: " << endl;
	testCubeConstructorAndDisplayAll();
	cout << endl << testCubeGetTopLetter() << endl;
	testCubeRollAndDisplayTop();
	cout << endl;*/

	/*cout << endl << "Test for the player functions: " << endl;
	testPlayerConstructorAndDisplay();
	testPlayerReadInfo();
	testPlayerReadWordsTimed();*/
	
	cout << endl << "Test for the Board functions: " << endl;

	//testBoardConstructorsAndDisplay();
	/*testBoardCubeInPosition();
	testBoardTopLetter();
	testBoardShuffle();*/
	testBoardFindWordanddisplayPath();

	//Bugs: se tiver  5 x 5 no ficheiro e nao houver cubos suficientes ele mostra cubos que nao existem.

	return 0;
}

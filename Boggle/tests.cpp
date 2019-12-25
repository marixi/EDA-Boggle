// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Dictionary.h"
#include"Cube.h"
using namespace std;

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



int main()
{
	cout << "Test for the dictionary functions: " << endl;
	testDictionaryConstructorAndDisplay();
	cout << testDictionaryFind() << endl;

	cout << endl << "Test for the cube functions: " << endl;
	testCubeConstructorAndDisplayAll();
	cout << endl << testCubeGetTopLetter() << endl;
	testCubeRollAndDisplayTop();
	cout << endl;

	return 0;
}

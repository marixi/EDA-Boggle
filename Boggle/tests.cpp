// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Dictionary.h"
using namespace std;

void testDictionaryConstructorAndDisplay()
{
	string filename = "WORDS_TEST.TXT";
	Dictionary dic(filename);
	dic.display(cout);
}

bool testDictionaryFind()
{
	return false;
}

int main()
{
	testDictionaryConstructorAndDisplay();
	return 0;
}
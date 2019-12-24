#include"Dictionary.h"
using namespace std;

int main()
{
	// read dictionary from filename
	string filename = "smallDictionary";
	Dictionary d;
	d.Dictionary::Dictionary(filename);
	// display dictionary
	d.Dictionary::display(cout);
	// find word in dictionary
	string word1 = "abacate";
	bool find1.Dictionary::find(word1);
	string word2 = "A";
	bool find2.Dictionary::find(word2);
	if (find1 == true && find2 == false)
		cout << "Find word is working just fine";
}
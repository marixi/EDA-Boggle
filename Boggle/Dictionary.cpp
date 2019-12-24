// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Dictionary.h"
using namespace std;

Dictionary::Dictionary(const string& filename)
{
	ifstream f(filename);

	if (f.fail())
		cerr << "Error: \"" << filename << "\" was not found! \n";

	int i = 0;
	string s;
	while (getline(f,s))
	{
		dictionary.insert(pair<int, string>(i, s));
		i++;
	}
}

//---------------------------------------------------------------------------------------------------------------
bool Dictionary::find(const string& word)
{
	bool foundWord = false;
	map<int, string>::const_iterator mi;
	pair<int, string> p;
	for (mi = dictionary.begin(); mi != dictionary.end(); mi++)
	{
		p = *mi;
		if (p.second == word)
			foundWord = true;
	}
	return foundWord;
}

//---------------------------------------------------------------------------------------------------------------
void Dictionary::display(ostream& os) const
{
	for (const auto& x : dictionary)
		os << x.second << endl;
}
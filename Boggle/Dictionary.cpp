// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Dictionary.h"
using namespace std;

Dictionary::Dictionary()
{
	_dictionary.insert(pair<int, string>(0, "NO WORDS"));
}
//---------------------------------------------------------------------------------------------------------------
Dictionary::Dictionary(const string& filename)
{
	// Checks if the text file exists.
	ifstream f(filename);
	if (f.fail())
	{
		cerr << "Error: \"" << filename << "\" was not found! \n";
		exit(1);
	}

	int i = 0;
	string s;
	while (getline(f,s))
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			s[i] = toupper(s[i]);
		}
		_dictionary.insert(pair<int, string>(i, s));
		i++;
	}

	// Closes the file stream.
	f.close();
}
//---------------------------------------------------------------------------------------------------------------
bool Dictionary::find(const string& word)
{
	bool foundWord = false;
	map<int, string>::const_iterator mi;
	pair<int, string> p;
	for (mi = _dictionary.begin(); mi != _dictionary.end(); mi++)
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
	for (const auto& x : _dictionary)
		os << x.second << endl;
}
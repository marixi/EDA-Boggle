// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Config.h"
using namespace std;

Config::Config()
{
	_filenameDictionary = "NO FILE";
	_filenameBoard = "NO FILE";
	_maxTime = 0;
	_minLetters = 0;
	_victoryPoints = 0;
}
//--------------------------------------------------------------------------------------------------------------
void Config::defineParameters(string aux, string& parameter)
{
	aux.erase(0, aux.find_first_of(':') + 2);
	parameter = aux;
}
//--------------------------------------------------------------------------------------------------------------
Config::Config(const string& filename)
{
	ifstream f(filename);

	if (f.fail())
		cerr << "Error: \"" << filename << "\" was not found! \n";

	
	string header, separator, aux;
	getline(f, header);
	getline(f, separator);
	vector<string> parameters = { "_filenameBoard", "_filenameDictionary", "_maxTime", "_minLetters", "_victoryPoints" };
	
	for (size_t i = 0; i < parameters.size(); i++)
	{
		getline(f, aux);
		defineParameters(aux, parameters[i]);
	}
	_filenameBoard = parameters[0];
	_filenameDictionary = parameters[1];
	_maxTime = stoi(parameters[2]);
	_minLetters = stoi(parameters[3]);
	_victoryPoints = stoi(parameters[4]);
}
//--------------------------------------------------------------------------------------------------------------
void Config::displayConfig(ostream& os) const
{
	os << "Configuration of the Boggle program:" << endl;
	os << "Board filename: " << _filenameBoard << endl;
	os << "Words filename: " << _filenameDictionary << endl;
	os << "Time per player bet(seconds): " << _maxTime << endl;
	os << "Minimum number of letters in a word: " << _minLetters << endl;
	os << "Number of points needed to win: " << _victoryPoints << endl;
}
//--------------------------------------------------------------------------------------------------------------
string Config::getFilenameDictionary()
{
	return _filenameDictionary;
}
//--------------------------------------------------------------------------------------------------------------
string Config::getFilenameBoard()
{
	return _filenameBoard;
}
//--------------------------------------------------------------------------------------------------------------
unsigned int Config::getMaxTime() const
{
	return _maxTime;
}
//--------------------------------------------------------------------------------------------------------------
unsigned int Config::getMinLetters() const
{
	return _minLetters;
}
//--------------------------------------------------------------------------------------------------------------
unsigned int Config::getVictoryPoints() const
{
	return _victoryPoints;
}


// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Cube.h"
using namespace std;

Cube::Cube()
{
	_letters = vector<char>(6, '*');
	_topSide = 0;
}
//--------------------------------------------------------------------------------------------------------------
Cube::Cube(const vector<char>& letters)
{
	_letters = letters;
	_topSide = 0;
}
//--------------------------------------------------------------------------------------------------------------
void Cube::roll()
{
	_topSide = rand() % 6;
}
//--------------------------------------------------------------------------------------------------------------
char Cube::getTopLetter() const
{
	return _letters[_topSide];
}
//--------------------------------------------------------------------------------------------------------------
void Cube::displayTop(ostream& os) const
{
	os << getTopLetter();
}
//--------------------------------------------------------------------------------------------------------------
void Cube::displayAll(ostream& os) const
{
	for (size_t i = 0; i < _letters.size(); i++)
	{
		os << _letters[i] << "  ";
	}
}
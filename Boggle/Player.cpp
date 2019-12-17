// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Player.h"

Player::Player()
{
	_name = "NO NAME";
	_age = 0;
}

Player::Player(string name)
{
	_name = name;
	_age = 0;
}
void Player::readInfo()
{
	cout << "Insert Player's name: "; cin >> _name;
	cout << "Insert Player's age: "; cin >> _age;
}
void Player::readWordsTimed(unsigned int duration)
{

}
void display(ostream& os) const;
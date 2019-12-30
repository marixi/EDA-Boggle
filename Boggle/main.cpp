// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Game.h"
using namespace std;

void set(Game& game)
{
	game.setGame("BOGGLE_CONFIG.txt");
	clrscr();
	game.readPlayers();
}

void loop(Game game)
{
	do {
		game.readPlayersWords();
		game.roundPoints(cout);
	} while (game.checkForVictory() == false);
	game.displayWinner(cout);
}

int main()
{
	setFontSize(18);

	cout << "EDA PROJECT" << endl << endl << "Boggle is loading... ";
	srand(time(NULL));
	Game game;
	set(game);
	loop(game);

	return 0;

}

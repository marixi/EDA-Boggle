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
	game.discoverReportFilename();
	game.gameReport(1);
}

void loop(Game& game)
{
	do {
		game.readPlayersWords();
		game.roundPoints(cout);
	} while (game.checkForVictory() == false);
	game.displayWinner(cout);
	game.gameReport(3);
}

int main()
{
	//fullscr(); mete a consola em fullscreen, só usar quando ja se tiver o menu feito e se quiser jogar o jogo até ao fim
	setFontSize(18);
	cout << "EDA PROJECT" << endl << endl << "Boggle is loading... ";
	srand((unsigned int)time(NULL));
	Game game;
	set(game);
	loop(game);
	return 0;
}

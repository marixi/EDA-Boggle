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
	game.gameReport(2);
}

int main()
{
	//fullscr(); mete a consola em fullscreen, só usar quando ja se tiver o menu feito e se quiser jogar o jogo até ao fim
	setFontSize(18);

	Config c("BOGGLE_CONFIG.txt");
	cout << "EDA PROJECT" << endl << endl;
	cout << "The Boggle Game focus on making words with the given board by associatingletters next to each other." << endl << endl;
	cout << "Rules:" << endl << endl;
	cout << "- Each play round lasts " << c.getMaxTime() << " seconds." << endl;
	cout << "- Each word must have more than " << c.getMinLetters() << " letters." << endl << endl;
	cout << "The goal of the game is to reach " << c.getVictoryPoints() << " points." << endl << endl << endl;
	cout << endl << "Boggle is loading... ";
	srand((unsigned int)time(NULL));
	Game game;
	set(game);
	loop(game);
	setcolor(0);//eheh
	return 0;
}

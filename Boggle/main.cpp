// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Game.h"
using namespace std;

void menu(unsigned int phase, Game& game);

void rules(Config c)
{
	cout << "EDA PROJECT" << endl << endl;
	cout << "The Boggle Game focus on making words with the given board by associating letters next to each other." << endl << endl;
	cout << "Rules:" << endl << endl;
	cout << "- Each play round lasts " << c.getMaxTime() << " seconds." << endl;
	cout << "- Each word must have more than " << c.getMinLetters() << " letters." << endl << endl;
	cout << "The goal of the game is to reach " << c.getVictoryPoints() << " points." << endl << endl << endl;
}

void set(Game& game)
{
	game.setGame("BOGGLE_CONFIG.txt");
	clrscr();
	game.readPlayers();
}

void loop(Game& game)
{
	do {
		game.discoverReportFilename();
		game.gameReport(1);
		game.readPlayersWords();
		game.roundPoints(cout);
	} while (game.checkForVictory() == false);
	game.displayWinner(cout);
	game.gameReport(2);
	system("pause");
	menu(2,game);
}

void menu(unsigned int phase, Game& game)
{
	switch (phase)
	{
	case 1:
	{
		string keepPlaying;
		int option;
		for (;;)
		{
			clrscr();
			cout << "Menu: " << endl;
			cout << "1. New Game" << endl;
			cout << "2. Quit Game" << endl;
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
			clrscr();
			if (option == 1)
			{
				game.clearPlayers();
				game.clearPoints();
				cout << endl << "Boggle is loading... ";
				set(game);
				loop(game);
				cin.clear();
			}
			else
			{
				break;
			}
		}
		break;
	}
	case 2:
	{
		string keepPlaying;
		int option;
		for (;;)
		{
			clrscr();
			cout << "Menu: " << endl;
			cout << "1. New Game" << endl;
			cout << "2. Play again" << endl;
			cout << "3. Exit to homepage" << endl;
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
			clrscr();
			if (option == 1)
			{
				game.clearPlayers();
				game.clearPoints();
				cout << endl << "Boggle is loading... ";
				set(game);
				loop(game);
				cin.clear();
			}
			else if (option == 2)
			{
				game.clearPoints();
				loop(game);
			}
			else
			{
				cout << "Thank you for playing! " << endl;
				break;
			}
		}
		break;
	}
	}
}

int main()
{
	fullscr();
	setFontSize(18);
	srand((unsigned int)time(NULL));
	Config c("BOGGLE_CONFIG.txt");
	Game game;
	rules(c);
	system("pause");
	menu(1, game);
	return 0;
}
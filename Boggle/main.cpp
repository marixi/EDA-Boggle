// Grupo 5
// Duarte Rodrigues
// Ricardo Brioso
// Mariana Xavier

#include"Game.h"
using namespace std;

void menu(Game& game);


//This function explains the rules of the game.
void rules(Config c)
{
	cout << "EDA PROJECT" << endl << endl;
	cout << "The Boggle Game focus on making words with the given board by associating letters next to each other." << endl << endl;
	cout << "Rules:" << endl << endl;
	cout << "- Each play round lasts " << c.getMaxTime() << " seconds." << endl;
	cout << "- Each word must have more than " << c.getMinLetters() << " letters." << endl << endl;
	cout << "The goal of the game is to reach " << c.getVictoryPoints() << " points." << endl << endl << endl;

	cout << "Group 5 Project made by:" << endl << "Duarte Rodrigues" << endl << "Ricardo Brioso" << endl << "Mariana Xavier" << endl << endl;
}


//This function is used to set up the game initially.
void set(Game& game)
{
	game.setGame("BOGGLE_CONFIG.txt");
	clrscr();
	game.readPlayers();
}


//This function is called after the set and only ends when one of the players wins.
void loop(Game& game)
{
	do
	{
		game.discoverReportFilename();
		game.gameReport(1);
		game.readPlayersWords();
		game.roundPoints(cout);
	} while (game.checkForVictory() == false);

	game.displayWinner(cout);
	game.gameReport(2);
	system("pause");
}


//This function displays the menu of the game.
void menu(Game& game)
{
	int option = 0;
	bool isFirstTime = true;

	for (;;)
	{
		clrscr();
		cout << "Menu: " << endl;
		cout << "1. New Game" << endl;
		if (isFirstTime == true) //game homepage
			cout << "2. Quit Game" << endl;
		else if (isFirstTime == false) // after it was played
		{
			cout << "2. Play Again" << endl;
			cout << "3. Quit Game" << endl;
		}

		// Here the user chooses the option.
		cout << endl;
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');
		clrscr();

		if (option == 1) // New Game
		{
			game.clearPlayers();
			game.clearPoints();
			cout << endl << "Boggle is loading... ";
			set(game);
			loop(game);
			cin.clear();
			isFirstTime = false;
		}
		else if (isFirstTime == false && option == 2) // Play Again
		{
			game.clearPoints();
			loop(game);
			isFirstTime = false;
		}
		else if ((isFirstTime == true && option == 2)||(isFirstTime == false && option == 3)) // Exit
		{
			cout << "Thank you for playing! " << endl;
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
	menu(game);
	return 0;
}
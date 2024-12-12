
#include "Battleships.h"
#include "BoardFactory.h"
#include "GameManager.h"

int main() {
	system("clear");
	// IF USE_COLOR_IN_CONSOLE is defined, the text will be printed in color
	#ifdef USE_COLOR_IN_CONSOLE
		cout << "\033[1;31m Bienvenue dans le jeu de la bataille navale ! \033[0m" << endl; // Prints the text in red if the terminal supports it
	#else
		cout << "Bienvenue dans le jeu de la bataille navale !" << endl; // Prints the text in red if the terminal supports it
	#endif
	
	BoardFactory boardFactory = BoardFactory();
	#ifdef USE_COLOR_IN_CONSOLE
		cout << "\033[1;31m Joueur 1, placez vos bateaux ! \033[0m" << endl; // Prints the text in red if the terminal supports it
	#else
		cout << "Joueur 1, placez vos bateaux !" << endl;
	#endif
	Board boardA = boardFactory.create_board();

	// Wait for the player to press enter
	cout << "Appuyez sur entree pour continuer" << endl;
	cin.ignore();
	cin.get();

	// Clear the console to hide the board of player 1
	system("clear");

	#ifdef USE_COLOR_IN_CONSOLE
		cout << "\033[1;31m Joueur 2, placez vos bateaux ! \033[0m" << endl; // Prints the text in red if the terminal supports it
	#else
		cout << "Joueur 1, placez vos bateaux !" << endl;
	#endif

	Board boardB = boardFactory.create_board();
	cout << "Appuyez sur entree pour continuer" << endl;
	cin.ignore();
	cin.get();
	system("clear");
	GameManager gameManager = GameManager(boardA, boardB);
	gameManager.play();
	return 0;
}
